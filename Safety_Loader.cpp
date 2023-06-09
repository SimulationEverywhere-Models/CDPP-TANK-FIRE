/*******************************************************************/

//					DESCRIPCION: Safety_Loader
//
//						AUTORES: Ahmed Sayed Ahmed
//
//						  EMAIL: ahm_alwhab@hotmail.com
//
//						  FECHA: 20/10/2008
//
/*******************************************************************/

#include "Safety_Loader.h"
#include "message.h"
#include "mainsimu.h"

/*******************************************************************
					* Safety_Loader Constructor
********************************************************************/
Safety_Loader::Safety_Loader(const string &name)
: Atomic( name )
	, Sin ( addInputPort( "Sin" ) )
	, out( addOutputPort( "out" ) )
	, preparationTime( 0, 0, 0, 0 )

{
}


/*******************************************************************/
/*						 Safety_Loader Init Function					   */
/*******************************************************************/

Model &Safety_Loader::initFunction()
{
	out_val = false;
	return *this ;
}


/*******************************************************************/
/*						Safety_Loader External Function						*/
/********************************************************************/

Model &Safety_Loader::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == Sin )
	{
		if( msg.value() == true ) // Safety was pressed.  stay active until an external event comes in.
		{
			out_val = true;
			holdIn( active, preparationTime);

		}
		else 		// Safety was released.  stay passive until an external event comes in.
		{
			out_val = false;
			holdIn( passive, preparationTime);
		}
	}
		return *this;
}

/*******************************************************************/
/*						Safety_Loader Output Function						*/
/********************************************************************/

Model &Safety_Loader::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, out_val ) ;
	return *this ;
}

/*******************************************************************/
/*						Safety_Loader Internal Function						*/
/********************************************************************/

Model &Safety_Loader::internalFunction( const InternalMessage & )
{
	holdIn ( state(), Time::Inf );
	return *this ;
}


