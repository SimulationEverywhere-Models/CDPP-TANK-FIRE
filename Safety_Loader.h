/*******************************************************************
*
*  DESCRIPCION: Safety_Loader
*
*  AUTORE:
*  		   Ahmed Sayed Ahmed
*
*  EMAIL: ahm_alwhab@hotmail.com
*
*  FECHA: 20/10/2008
*
*******************************************************************/
#ifndef __SAFETY_LOADER_H
#define __SAFETY_LOADER_H

#include "atomic.h"     // class Atomic
#include "time.h"

class Safety_Loader : public Atomic
{
public:
	Safety_Loader( const string &name = "Safety_Loader" );
    virtual string className() const {  return "Safety_Loader" ;}
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &Sin;
	Port &out;
    Time preparationTime;
	bool out_val;
};	// class Safety_Loader

#endif   //__SAFETY_LOADER_H
