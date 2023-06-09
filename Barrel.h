/*******************************************************************
*
*  DESCRIPCION: Barrel
*
*  AUTORE:
*  		   Ahmed Sayed Ahmed
*
*  EMAIL: ahm_alwhab@hotmail.com
*
*  FECHA: 20/10/2008
*
*******************************************************************/
#ifndef __BARREL_H
#define __BARREL_H

#include "atomic.h"     // class Atomic
#include "time.h"

class Barrel : public Atomic
{
public:
	Barrel( const string &name = "Barrel" );
	virtual string className() const ;
	//   virtual string className() const {  return "Barrel" ;}


protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &Sfin, &Ain, &Fin;
	Port &Ammu_out;
    Time preparationTime;
	bool	Sfin_val, Ain_val, Fin_val, Ammu_out_val;
};	// class Barrel

// ** inline ** //
inline
string Barrel :: className() const
{
	return "Barrel" ;
}

#endif   //__BARREL_H
