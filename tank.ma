[top]
components : LOADER GUNNER 
in : Ammu_in Safety_in Elec_in Manu_in Emerg_in 
out :  Amm_out
Link : Ammu_in Ain@LOADER
Link : Safety_in Sin@LOADER
Link : Elec_in Ecin@GUNNER
Link : Manu_in Min@GUNNER
Link : Emerg_in Emin@GUNNER
Link : out@GUNNER Fin@LOADER
Link : Ammu_out@LOADER Amm_out

[LOADER]
components : Barrel@Barrel  Safety_Loader@Safety_Loader 
in : Ain Sin Fin
out : Ammu_out 
Link : Ain Ain@Barrel
Link : Fin Fin@Barrel
Link : Sin Sin@Safety_Loader
Link : out@Safety_Loader Sfin@Barrel
Link : Ammu_out@Barrel Ammu_out


[GUNNER]
components : Electric_Fire@Electric_Fire  Manual_Fire@Manual_Fire Emergency_Fire@Emergency_Fire Fire@Fire
in : Ecin Min Emin
out : out 
Link : Ecin in@Electric_Fire
Link : Min in@Manual_Fire
Link : Emin in@Emergency_Fire
Link : out@Electric_Fire Ecin@Fire
Link : out@Manual_Fire Min@Fire
Link : out@Emergency_Fire Emin@Fire
Link : out@Fire out


