/*******************************************************************/

//					DESCRIPCION: Emergency_Fire
//
//						AUTORES: Ahmed Sayed Ahmed
//
//						  EMAIL: ahm_alwhab@hotmail.com
//
//						  FECHA: 20/10/2008
//
/*******************************************************************/
#include "Emergency_Fire.h"
#include "message.h"
#include "mainsimu.h"

/*******************************************************************
					* Emergency_Fire Constructor
********************************************************************/
Emergency_Fire::Emergency_Fire(const string &name)
: Atomic( name )
	, in ( addInputPort( "in" ) )
	, out( addOutputPort( "out" ) )
    , preparationTime( 0, 0, 0, 4 )
    {
    }


/*******************************************************************/
/*						 Emergency_Fire Init Function					   */
/*******************************************************************/

Model &Emergency_Fire::initFunction()
{
	out_val = false;
	return *this ;
}


/*******************************************************************/
/*						Emergency_Fire External Function						*/
/********************************************************************/

Model &Emergency_Fire::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
		if( msg.value() == true ) // Emergency Fire Fire was pressed.
		{
			out_val = true;
			holdIn( active, preparationTime );
		}
	}
	return *this;
}

/*******************************************************************/
/*						Emergency_Fire Output Function						*/
/********************************************************************/

Model &Emergency_Fire::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, out_val ) ;
	return *this ;
}

/*******************************************************************/
/*						Emergency_Fire Internal Function						*/
/********************************************************************/

Model &Emergency_Fire::internalFunction( const InternalMessage & )
{
	out_val = false;
	passivate();
	return *this ;
}


