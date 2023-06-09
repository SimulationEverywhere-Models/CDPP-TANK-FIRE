/*******************************************************************
*
*  DESCRIPCION: Electric_Fire
*
*  AUTORE:
*  		   Ahmed Sayed Ahmed
*
*  EMAIL: ahm_alwhab@hotmail.com
*
*  FECHA: 20/10/2008
*
*******************************************************************/
#ifndef __ElECTRIC_FIRE_H
#define __ElECTRIC_FIRE_H

#include "atomic.h"     // class Atomic
#include "time.h"

class Electric_Fire : public Atomic
{
public:
	Electric_Fire( const string &name = "Electric_Fire" );
    //virtual string className() const {  return "Electric_Fire" ;}
    virtual string className() const ;
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
};	// class Electric_Fire
// ** inline ** //
inline
string Electric_Fire :: className() const
{
	return "Electric_Fire" ;
}
#endif   //__ElECTRIC_FIRE_H
