#include "light_control.h"
#include "interface.h"
#include "climate.h"
#include "leakage.h"
#include "sms.h"
#include "comandos.h"
#include "presence.h"

void setup(void)
{
  interface.setup();
  presence.setup();
  leakage.setup();
  climate.setup();
  light.setup();
  sms.setup();
  comandos.setup();
}

void loop(void)
{
  while(1)
  {
    comandos.controlInterface();
    comandos.controlLight();
    comandos.controlTemperature();
    comandos.leakageAlert();
  }
}
