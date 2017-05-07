# Self-Driving Car Engineer Nanodegree
# Robotics: Localization
## Project: PID Controller

---

### Overview
This is the 9th project of the [Self Driving Car Engineer Nanodegree](https://www.udacity.com/course/self-driving-car-engineer-nanodegree--nd013) I am taking part. <br>
The aim of this project was to build a PID controller in order to drive a car on a simulator. 


### Roles of P, I, and D
- <b>Proportionnal coefficient (P)</b><br/>
THe role of P is to make the car "drifting" toward the CTE, by multiplying the CTE by P value (I find by trial/error that `0.225` was a good value). However, it will never quite reach the CTE, but will oscillate around it. This will results in a not so-safe driving behaviour. That is why we will also use I and D terms.
- <b>Integral coefficient (I)</b><br/>
The role of the I's term is to compensate systematic bias. For example if the steering of the car has been wrongly fixed and has a tendancy to steer a bit to the right, the I's term will compensate that. It will accumulate the value of the surface between the position of the car and the CTE over time, and multiply this by the value of the I's term. I gave chosen to first set this value to a very small number since theres is no sysmtematic bias coded in the simulator. It appeared later that i obtained better results by just setting it to 0. 
- <b>Differential coefficient (D)</b><br/
Once the car began to steer tomards the CTE, it will be aware of it and start to counter-steer. This is done by the differential term, wich goes smaller as the car drives towards the CTE. This will avoid the over-shooting previously caused by the P controller alone. My first try was to set it to `3.0`, but I found out it has little effect to the simulator when setiing higher value. 

### Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases) in the classroom.

### Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 
