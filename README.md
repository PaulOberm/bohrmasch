# bohrmasch
DIY Drehzahlanzeiger für eine Ständerbohrmaschine über Arduino. Dort wird an
der Spindel ein Magnet montiert um die Drehzahl der Spindel in U/min zu ermitteln.

An einer gebrauchten Ständerbohrmaschine mit Kabeltrieb fehlt eine
Drehzahlmessung sowie folglich deren Anzeige.
Als technische Lösung wird ein **Arduino UNO** mit einer Standarddigitalanzeige
**QAPAS 1602A** umgesetzt.

Der Aufbau kann mit einem einfachen Küchenmagneten getestet werden.

## Quellen

* Anschluss und Auswahl des Hall-Sensors: http://bollwerk-essen.bplaced.net/?hall_sensor
* Ähnlicher Anschluss des LCD: https://www.arduino.cc/en/Tutorial/HelloWorld
* Konfiguration eines Interrupts auf dem Arduino: http://diwo.bq.com/de/interrupts-mit-arduino-benutzen/

## Bauteile

1. Arduino UNO
2. Knopfschalter (Ein/Aus)
3. Potentionmeter - 1x - 10kOhm
4. LED (Ein/Aus)
5. Widerstand - 1x - 10 kOhm
6. Widerstand - 1x - 1 kOhm
7. LCD Digitalanzeige QAPAS 1602A
8. Hall-Sensor (https://www.buerklin.com/de/Hallsensor-A1126LUA-T/p/51S102)
9. Magnet (https://www.conrad.de/de/p/maul-neodym-magnet-x-h-10-mm-x-3-mm-scheibe-silber-10-st-6166396-1796544.html)
