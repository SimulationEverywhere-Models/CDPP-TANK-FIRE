/*******************************************************************/

//					DESCRIPCION: Electric_Fire
//
//						AUTORES: Ahmed Sayed Ahmed
//
//						  EMAIL: ahm_alwhab@hotmail.com
//
//						  FECHA: 20/10/2008
//
/*******************************************************************/

#include "Electric_Fire.h"
#include "message.h"
#include "mainsimu.h"

/*******************************************************************
					* Electric_Fire Constructor
********************************************************************/
Electric_Fire::Electric_Fire(const string &name)
: Atomic( name )
	, in ( addInputPort( "in" ) )
	, out( addOutputPort( "out" ) )
    , preparationTime( 0, 0, 0, 4 )

{
}


/*******************************************************************/
/*						 Electric_Fire Init Function					   */
/*******************************************************************/

Model &Electric_Fire::initFunction()
{
//	this->out_val = false;
	out_val = false;
	return *this ;
}


/*******************************************************************/
/*						Electric_Fire External Function						*/
/********************************************************************/

Model &Electric_Fire::externalFunction( const ExternalMessage &msg )
{
	cout <<  "Hi_ext out output  : " ;


	if( msg.port() == in )
	{
		if( msg.value() == true ) // Electric Fire was pressed.
		{
			out_val = 1;
			holdIn( active, preparationTime );
		}
	}

	return *this;
}

/*******************************************************************/
/*						Electric_Fire Output Function						*/
/********************************************************************/

Model &Electric_Fire::outputFunction( const InternalMessage &msg )
{
	  sendOutput( msg.time(), out, out_val ) ;
	return *this ;
}

/*******************************************************************/
/*						Electric_Fire Internal Function						*/
/********************************************************************/

Model &Electric_Fire::internalFunction( const InternalMessage & )
{
	out_val = 0;
	passivate();
	return *this ;
}


