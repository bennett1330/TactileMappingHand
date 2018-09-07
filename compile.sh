g++ -c GpioSetup.cpp -g -o GpioSetup.o
g++ -c MotorSetup.cpp -g -o MotorSetup.o
g++ -c SelectSetup.cpp -g -o SelectSetup.o
g++ -c StepSetup.cpp -g -o StepSetup.o
g++ -c EncoderSetup.cpp -g -o EncoderSetup.o
g++ -c StepperConfig.cpp -g -o StepperConfig.o
g++ -c DcConfig.cpp -g -o DcConfig.o
g++ -c FsrSetup.cpp -g -o FsrSetup.o
g++ -c MeasurementConfig.cpp -g -o MeasurementConfig.o
g++ GpioSetup.o MotorSetup.o SelectSetup.o StepSetup.o EncoderSetup.o StepperConfig.o DcConfig.o FsrSetup.o MeasurementConfig.o Main.cpp -g -o Main -l bcm2835 -l pthread