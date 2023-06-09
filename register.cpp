/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Ahmed Sayed Ahmed
*
*  EMAIL: ahm_alwhab@hotmail.com
*
*  DATE: 20/10/2008
*
*******************************************************************/

#include "modeladm.h"
#include "mainsimu.h"
#include "Barrel.h"				// class Barrel
#include "Safety_Loader.h"		// class Safety_Loader
#include "Electric_Fire.h"		// class Electric_Fire
#include "Manual_Fire.h"		// class Manual_Fire
#include "Emergency_Fire.h"		// class Emergency_Fire
#include "Fire.h"				// class Fire
#include "cpu.h"        // class CPU


void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Barrel>()			, "Barrel" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Safety_Loader>()	, "Safety_Loader" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Electric_Fire>()	, "Electric_Fire" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Manual_Fire>()		, "Manual_Fire" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Emergency_Fire>()	, "Emergency_Fire" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Fire>()			, "Fire" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CPU>() , "CPU" ) ;

}
