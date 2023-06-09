/*******************************************************************/

//					DESCRIPCION: Barrel
//
//						AUTORES: Ahmed Sayed Ahmed
//
//						  EMAIL: ahm_alwhab@hotmail.com
//
//						  FECHA: 20/10/2008
//
/*******************************************************************/

#include "Barrel.h"
#include "message.h"
#include "mainsimu.h"

/*******************************************************************
					* Barrel Constructor
********************************************************************/
Barrel::Barrel(const string &name)
: Atomic( name )
	, Sfin( addInputPort( "Sfin") )
	, Ain ( addInputPort( "Ain" ) )
	, Fin ( addInputPort( "Fin" ) )
	, Ammu_out( addOutputPort( "Ammu_out" ) )
	, preparationTime( 0, 0, 0, 2 )

{
}

/*******************************************************************/
/*						 Barrel Init Function					   */
/*******************************************************************/

Model &Barrel::initFunction()
{
	Sfin_val = false;
	Ain_val = false;
	Fin_val = false;
	Ammu_out_val = false;

	return *this ;
}


/*******************************************************************/
/*						Barrel External Function						*/
/********************************************************************/

Model &Barrel::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == Sfin )
	{
	   if( msg.value() == true )
		Sfin_val = true;
	   else
		   Sfin_val = false;

	}

	if( msg.port() == Ain )
	{
	   if( msg.value() == true )
		// Ammu was loaded.
		Ain_val = true;
	   else
		Ain_val = false;
	}
	if( msg.port() == Fin )
	{
	   if( msg.value() == true )
			Fin_val = true;
	}

	if (Sfin_val && Ain_val && Fin_val)
	{
		Ammu_out_val = true;
        holdIn( active, preparationTime );
	}

	return *this;
}

/*******************************************************************/
/*						Barrel Output Function						*/
/********************************************************************/

Model &Barrel::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), Ammu_out, Ammu_out_val ) ;
	return *this ;
}

/*******************************************************************/
/*						Barrel Internal Function						*/
/********************************************************************/

Model &Barrel::internalFunction( const InternalMessage & )
{
	Ain_val = false;
	Fin_val = false;
	Ammu_out_val = false;
	passivate();
	return *this ;
}



