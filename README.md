# Development of an Autonomous Robotic Pick and Place Laboratory Setup for Intelligent Industrial Automation

 ![Alt Text](https://raw.githubusercontent.com/tursynbekoff/robotic_hand/master/real_VS_solid.jpg)
*  3D Design of the Hand 
*  Control of the hand 

## 3D Design of the Hand
The robotic hand is still under iprovement and development stage. Here is shown previous models and developmemt steps that have been done. First model of the hand was done not by me and in a limited period of time. My goal is to improve design and eliminate problems from initial model. 

### Problems of initial model
* Thumb was broken
* Backlash between parts 
* Wires were exposed to mechanical deformation
 ![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/thumb_1.0.jpg)
 ![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/comparison-min.jpg)
 ![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/wire_old_vs_new.jpg)
 
The problem with backlash was solved by replacing old parts with new ones. Decreasing the backlash improved sensor readings and precision of the hand. The new design of the "proximal phalanges" of the hand allowed to decrease backlash and new placement for position sensors and locate the wiring of the sensors inside the hand. The advantage of placing position sensor inside the finger, the data readings from sensor are cleaner and new placement also secures wiring from mechanical exposure.
### Setps of development of the new design of the thumb
The first picture demostrates initial design of the thumb
![Alt Text](https://github.com/tursynbekoff/robotic_hand/blob/master/REPORT_git/init_1.jpg)
The first updated design of the thumb consisted from following configuration: exion mechanism is performed with aid of brushed DC motor with integrated gearbox. The worm gear rotates spur gear which in turn performs extension, exion movements. Moreover, the mechanism is non-backdrivable and performs in a positive way at grabbing operation. In addition, thumb can perform underactuated adaptive closing through linkage connections. While extension, flexion operations thumb can bend depending on the placement of the object and wrap around that object. The second brushed DC motor rotates thumb with spur gear about its axis at "thumb's up" position. Thus, the thumb could perform only extension, flexion movements. However, the thumb in this configuration cannot perform abduction, adduction motions. As a result, the thumb cannot perform grabbing operation and further changes were made.

 

