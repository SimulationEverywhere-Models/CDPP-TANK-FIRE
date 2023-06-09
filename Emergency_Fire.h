/*******************************************************************
*
*  DESCRIPCION: Emergency_Fire
*
*  AUTORE:
*  		   Ahmed Sayed Ahmed
*
*  EMAIL: ahm_alwhab@hotmail.com
*
*  FECHA: 20/10/2008
*
*******************************************************************/
#ifndef __EMERGENCY_FIRE_H
#define __EMERGENCY_FIRE_H

#include "atomic.h"     // class Atomic
#include "time.h"

class Emergency_Fire : public Atomic
{
public:
	Emergency_Fire( const string &name = "Emergency_Fire" );
    virtual string className() const {  return "Emergency_Fire" ;}
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in;
	Port &out;
    Time preparationTime;
	bool out_val;
};	// class Emergency_Fire

#endif   //__EMERGENCY_FIRE_H
