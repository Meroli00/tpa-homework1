# tpa-homework1
Homework n1, Advanced Programming Course held by professor Leoni David 

## Device: catapult
The chosen device is a catapult.
Its variable parameters are:
- wheel radius
- arm length 
- launch angle
- hight of the structure holding the arm
- hight of the base

![](https://github.com/MuttiGiacomo/tpa-homework1/blob/main/Catapult_legenda.svg)

Based uppon the variables stated above there are several constraints:
- all dimensions must be > 0 and < of a certain max value
- hc < 2 times the radius
- the launch angle is limited and depends on hc


(due to linking error to the string library the .exe file has to be generated by typing
g++ main.cpp mgCatapult.cpp -std=c++11 )


## Machine: catapult + car
The user will be able to configure both car and catapult.
The result will bee a svg file such as:

![](https://github.com/MuttiGiacomo/tpa-homework1/blob/main/machineNC.svg)
