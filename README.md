## Persistence Library for storing structs in an esp32's eeprom

#### Example usage
```
#include "persistence.h"

typedef struct
{
  uint8_t value;
  bool enabled;
} Config;

template class Persistence<Config>;

#define P_NAMESPACE "Config"
#define P_TYPE Config

void setup()
{
    Serial.begin(115200);
    Persistence<P_TYPE> configuration(P_NAMESPACE);

    if (!configuration.loadData())
        Serial.println("Could not load data from persistence");
    else {
        Serial.println("Loaded data from persistence");
        Config config = configuration.getData();

        Serial.print("Value: "); Serial.println(config.value);
        Serial.print("Enabled: "); Serial.println(config.enabled);
    }

    Config newConfig = {0x01, true};

    if (!configuration.updateData(&newConfig))
        Serial.println("Could not update data in memory");
    else
        Serial.println("Updated data in memory");
}
```
