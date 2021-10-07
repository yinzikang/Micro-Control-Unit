typedef struct PID _tag{
double SetPoint; // ???? Desired Value
double Proportion; // ???? Proportional Const
double Integral; // ???? Integral Const
double Derivative; // ???? Derivative Const
double LastError; // Error[-1]
double PrevError; // Error[-2]
double SumError; // Sums of Errors
} PID;

double PIDCalc( PID *pp, double NextPoint )
{
double dError,Error;
Error = pp->SetPoint - NextPoint; // ??,??????????
pp->SumError += Error; // ??,??????
dError = pp->LastError - pp->PrevError; // ????,????
pp->PrevError = pp->LastError;
pp->LastError = Error;
return (pp->Proportion * Error // ???
+ pp->Integral * pp->SumError // ???
+ pp->Derivative * dError // ???);
}

double sensor (void) // Dummy Sensor Function
{
return 100.0;
}

void actuator(double rDelta) // Dummy Actuator Function
{

}

void main(void)
{
PID sPID; // PID Control Structure
double rOut; // PID Response (Output)
double rIn; // PID Feedback (Input)
sPID.Proportion = 0.5; // Set PID Coefficients
sPID.Integral = 0.5;
sPID.Derivative = 0.0;
sPID.SetPoint = 100.0; // Set PID Setpoint

for (;;) { 
rIn = sensor (); /*???????*/
rOut = PIDCalc ( &sPID,rIn );
actuator ( rOut );
}
}