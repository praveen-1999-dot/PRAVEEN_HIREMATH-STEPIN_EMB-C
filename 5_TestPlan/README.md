# Test Plans

|  Test ID | Description  | Input  | Output  |
|---|---|---|---|
| TID_01  | Is person enters or exist  | switch=1| LED ON|
| TID_02  | Is person not enters or exist  | switch=0|LED OFF|
| TID_03  | Temperature request | Temp=0| Heater Off |
| TID_04  | Temperature Request | Temp=20| Heater On 20degree of heat generation |
| TID_05  | Temperature Request | Temp=25| Heater On 25degree of heat generation|
| TID_06  | Temperature Request | Temp=29| Heater On 29degree of heat generation |
| TID_07  | Temperature Request | Temp=33| Heater On 33degree of heat generation |
| TID_08  | LED ON | Button=1 && Heater=1| LED ON and Voltmeter Will show 5V |
| TID_09  | LED OFF | Button=0 && Heater=0| LED OFF and Voltmeter will show 0V |
| TID_10  | LCD Display | Temperature :)<br />20 deg Cel| Temperature :)<br />20 deg Cel|
