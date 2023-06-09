/*******************************************************************/

//					DESCRIPCION: Manual_Fire
//
//						AUTORES: Ahmed Sayed Ahmed
//
//						  EMAIL: ahm_alwhab@hotmail.com
//
//						  FECHA: 20/10/2008
//
/*******************************************************************/

#include "Manual_Fire.h"
#include "message.h"
#include "mainsimu.h"

/*******************************************************************
					* Manual_Fire Constructor
********************************************************************/
Manual_Fire::Manual_Fire(const string &name)
: Atomic( name )
	, in ( addInputPort( "in" ) )
	, out( addOutputPort( "out" ) )
    , preparationTime( 0, 0, 0, 4 )
    {
    }


/*******************************************************************/
/*						 Manual_Fire Init Function					   */
/*******************************************************************/

Model &Manual_Fire::initFunction()
{
	out_val = false;
	return *this ;
}


/*******************************************************************/
/*						Manual_Fire External Function						*/
/********************************************************************/

Model &Manual_Fire::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
		if( msg.value() == true ) // Manual_Fire Fire was pressed.
		{
			out_val = true;
			this->holdIn( active, preparationTime );
		}
	}

	return *this;
}

/*******************************************************************/
/*						Manual_Fire Output Function						*/
/********************************************************************/

Model &Manual_Fire::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, out_val ) ;
	return *this ;
}

/*******************************************************************/
/*						Manual_Fire Internal Function						*/
/********************************************************************/

Model &Manual_Fire::internalFunction( const InternalMessage & )
{
	out_val = false;
	passivate();
	return *this ;
}


