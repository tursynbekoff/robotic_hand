# Development of an Autonomous Robotic Pick and Place Laboratory Setup for Intelligent Industrial Automation
    
 ![Alt Text](https://raw.githubusercontent.com/tursynbekoff/robotic_hand/master/real_VS_solid.jpg)
The anthropomorphic hand consist of mechanical design and electrical components like 12V DC motor, arduino microcontroller wiring and PCB. In the following parts there will be full description of the mechanican and electrical components and source files could be found in the folders above

[![Video](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/Capture.JPG)](https://youtu.be/M6sOJtzTVpo)

*  3D Design of the Hand 1.0
*  3D Design of the Hand 2.0
*  Control of the hand 

## 3D Design of the Hand 1.0
The robotic hand is still under iprovement and development stage. Here is shown previous models and developmemt steps that have been done. First model of the hand was done not by me and in a limited period of time. My goal is to improve design and eliminate problems from initial model. 

### Problems of the initial model
* Thumb was broken
* Backlash between parts 
* Wires were exposed to mechanical deformation
 ![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/thumb_1.0.jpg)
 ![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/comparison-min.jpg)
 ![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/wire_old_vs_new.jpg)
 
The problem with backlash was solved by replacing old parts with new ones. The new design of the "proximal phalanges" of the hand allowed to decrease backlash and the new placement of position sensors and location of the wiring of the sensors inside the hand improved sensor readings and precision of the hand. The advantage of placing position sensor inside the finger is straighforward, the data readings from sensor are cleaner and new placement also secures wiring from mechanical exposure.
### Setps of development of the new design of the thumb

The first picture demostrates initial design of the thumb

![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/init_1.jpg)
The first updated design of the thumb consisted from following configuration: flexion mechanism is performed with aid of brushed DC motor with integrated gearbox. The worm gear rotates spur gear which in turn performs extension, flexion movements. Moreover, the mechanism is non-backdrivable and performs in a positive way at grabbing operation it secures position even after power loss. In addition, thumb can perform underactuated adaptive closing through linkage connections. While extension, flexion operations thumb can bend depending on the placement of the object and wrap around that object. The second brushed DC motor rotates thumb with spur gear about its axis at "thumb's up" position. Thus, the thumb could perform only extension, flexion movements. However, the thumb in this configuration cannot perform abduction, adduction motions. As a result, the thumb cannot perform grabbing operation and further changes were made.

![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/rotat_one.jpg)

The second design of the thumb is different from initial design with the placement of the second brushed DC motor. Middle shaft were used to rotate thumb about palm plane. The thumb moves inward and outward from the palm plane, that means it can perform flexion, extension as well as abduction, adduction movements. However, this mechanism needs more space and eventually the design of the thumb were rebuilt.
![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/last_1.jpg)

The next CAD model of the thumb can rotate about its base and can perform  flexion, extension and adduction. Placing the thumb opposite to index finger it can perform extension, flexion, abduction and adduction movements. In addition, this design does not need much space and can be compact in size. Space is needed only for DC motor. As a result, this CAD design is more effcient. The next design iterations  are fundamentally the same. The placement of the first DC motor is the same and adaptive mechanism is rotated to 90 degrees and placed opposite to index finger. The second brushed DC motor rotates the thumb around index finger axis by using bevel gear. The advantage using bevel gear instead of spur gear, it conserves space. As a result, we started printing the parts.

![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/inter_mid_des-min.jpg)
 
The last design: 

![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/last-min.jpg)

The next iteration was connection of mechanical part with electrical components. Due to dynamic configuration of the thumb and moving mechanical structures of the hand it created diffculties with wiring. DC motors, that were used in the project, has embedded quadratic encoders, therefore each motor has six pins to connect. The first DC motor is integrated in the moving structure that rotates around its axis. The second DC motor rotates the structure with the first DC motor. The requirement for the harness is flexibility and transmitting rated power for the motor. As a result, the wiring loom was made from copper wires that widely used in headphones. In addition, mechanical changes were made for harness wiring, it goes through narrow slot in the moving part and protected from mechanical deformation. However, the part of the wire harness which connects dynamic part with static part is exposed to bending. To secure robustness of the exposed part of the harness, insulating tape was used. 

![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/harness_wire-min.jpg)
![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/cord-min.JPG)

As a result, the final CAD model of the thumb can perform extension, flexion and abduction, adduction movements. The main difference between initial and the final model of the thumb, it can perform under-actuated adaptive motion, which means the thumb can wrap around object with complex geometrical shape and simplifies the control of the thumb. Full up-to-date CAD model of the hand is [here](https://github.com/tursynbekoff/robotic_hand/tree/master/CAD).


### Holding objects

[![IMAGE ALT TEXT HERE](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/youtube.PNG)](https://youtu.be/hmZBOrk-Xx8)

The performance of the hand with new thumb was tested with various objects. In the test
there were objects with different shapes: cylindrical, spherical and brick shaped. The hand
performed grabbing with aid of manual manipulation. The hand securely holds all objects and thumb performs adaptive gripping of the objects. Underactuated adaptive bending of the thumb helps to grab and to hold objects. However, the length and the shape of the thumb should be tuned for versatility. The grip of the thumb can be improved by adding nonbackdivable mechanism where bevel gear is placed. Other possible way to improve the grip, by resin coating on the contact point with the object, on the inner surface of the thumb.

![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/sph3-min.JPG)
![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/cyl3-min.JPG)
![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/bri2-min.JPG)
![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/screw-min.JPG)
![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/pen-min.JPG)

In addition, household objects with complex geometrical configuration, as screwdriver, were tested. The hand can grab the objects with external manipulation and securely hold objects at specific position. The hand has potential to be used as prosthesis.

## Hand 2.0
### New Finger Mechanism
currently working on adaptive underactuated mechanism for fingers

![Demo](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/Finger_Mechanism.gif)
CAD files for finger are [here](https://github.com/tursynbekoff/robotic_hand/tree/master/test_finger)

![Demo](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/ezgif.com-rotate.gif)

New hand with rail sysem for stablitity and robustness is under integration process.
![New hand](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/New_hand_1.JPG)
The crossed structures are used for stiffness and strength to hold rails stable. Rails are used to navigate motor joint part durring mechanical transition from rotational motion to linear motion. Earlier there was no rail system and there were parisite vibration in rotaional motion which created disturbance in postion sensor readings. From the first tests fingers move in defined trajectory. 
![New hand](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/New_hand.JPG)

## Control of the hand

All fingers of the hand equipped with encoders: 2 quadrature encoders for thumb and position sensor for other fingers. This is necessary to receive position feedback and avoid critical points, that can destroy finger structure and motor. There are six brushless DC motors that require dual motor drivers (DRV8835). For dual motor driver, 4 motor control signals (2 signal per motor) is sent from Arduino. The signal to the motors must be PWM, while the other zero to move in one direct, the opposite to move in reverse direction. If both signals are zero, motor stops. Apart from that, 10V with 1A power is connected to Vcc that is supplied to the motors. Initially all the electrical components were connected to the breadbord. Breadbord caused many hardware problems with robustness of the system. As a result, the idea of creating PCB was in demand. PCB was designed in CicuitMaker(open source free software). New PCB eliminates potential hardware failures and serves as a 6-channel Arduino motor shield and I/O for digital and analog pins. In addition, to secure from environment and potential mechanical failure, housing was developed and files for housing could be found in the folder [Housing](https://github.com/tursynbekoff/robotic_hand/tree/master/Housing).
![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/PCB.jpg)
![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/PCB_old_vs_new.jpg)
![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/new_PCB_housing.jpg)
Full **PCB** design could be found from the following [link](https://circuitmaker.com/Projects/Details/Talgat-Tursynbekov/Robotic-hand). Full **script** for hand controll is [here](https://github.com/tursynbekoff/robotic_hand/tree/master/Control/hand_control_1.0). 



