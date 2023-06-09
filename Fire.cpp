/*******************************************************************/

//					DESCRIPCION: Fire
//
//						AUTORES: Ahmed Sayed Ahmed
//
//						  EMAIL: ahm_alwhab@hotmail.com
//
//						  FECHA: 20/10/2008
//
/*******************************************************************/

#include "Fire.h"
#include "message.h"
#include "mainsimu.h"

/*******************************************************************
					* Fire Constructor
********************************************************************/
Fire::Fire(const string &name)
: Atomic( name )
	, Ecin( addInputPort( "Ecin") )
	, Min ( addInputPort( "Min" ) )
	, Emin ( addInputPort( "Emin" ) )
	, out( addOutputPort( "out" ) )
    , preparationTime( 0, 0, 0, 4 )
    {
    }

/*******************************************************************/
/*						 Fire Init Function					   */
/*******************************************************************/

Model &Fire::initFunction()
{
	out_val = false;
	return *this ;
}


/*******************************************************************/
/*						Fire External Function						*/
/********************************************************************/

Model &Fire::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == Ecin )
	{
		if( msg.value() == true ) // Electric Fire was pressed.
		{
			out_val = true;
			holdIn( active, preparationTime );
		}
	}

	if( msg.port() == Min )
	{
		if( msg.value() == true ) // Manual Fire was pressed.
		{
			out_val = true;
			holdIn( active, preparationTime );
		}
	}

	if( msg.port() == Emin )
	{
		if( msg.value() == true ) // Emeregency Fire was pressed.
		{
			out_val = true;
			holdIn( active, preparationTime );
		}
	}

	return *this;
}

/*******************************************************************/
/*						Fire Output Function						*/
/********************************************************************/

Model &Fire::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, out_val ) ;
	return *this ;
}

/*******************************************************************/
/*						Fire Internal Function						*/
/********************************************************************/

Model &Fire::internalFunction( const InternalMessage & )
{
	out_val = false;
	passivate();
	return *this ;
}


