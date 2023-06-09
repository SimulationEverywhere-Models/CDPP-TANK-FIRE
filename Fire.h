/*******************************************************************
*
*  DESCRIPCION: Fire
*
*  AUTORE:
*  		   Ahmed Sayed Ahmed
*
*  EMAIL: ahm_alwhab@hotmail.com
*
*  FECHA: 20/10/2008
*
*******************************************************************/
#ifndef __FIRE_H
#define __FIRE_H

#include "atomic.h"     // class Atomic
#include "time.h"

class Fire : public Atomic
{
public:
	Fire( const string &name = "Fire" );
    virtual string className() const {  return "Fire" ;}
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &Ecin, &Min, &Emin;
	Port &out;
    Time preparationTime;
	bool	out_val;
};	// class Fire

#endif   //__FIRE_H
