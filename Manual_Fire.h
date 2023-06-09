/*******************************************************************
*
*  DESCRIPCION: Manual_Fire
*
*  AUTORE:
*  		   Ahmed Sayed Ahmed
*
*  EMAIL: ahm_alwhab@hotmail.com
*
*  FECHA: 20/10/2008
*
*******************************************************************/
#ifndef __MANUAL_FIRE_H
#define __MANUAL_FIRE_H

#include "atomic.h"     // class Atomic
#include "time.h"

class Manual_Fire : public Atomic
{
public:
	Manual_Fire( const string &name = "Manual_Fire" );
    virtual string className() const {  return "Manual_Fire" ;}
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
};	// class Manual_Fire

#endif   //__MANUAL_FIRE_H
