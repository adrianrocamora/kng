#include <iostream>

struct PID {
    double  dState;      // Last position input
    double  iState;      // Integrator state
    double  iMax, iMin;  // Limits for allowable integrator state
    double  iGain,       // Integral gain
            pGain,       // Proportional gain
            dGain;       // Derivative gain
};

double updatePID(PID& pid, double error, double position) {
    double pTerm, dTerm, iTerm;
    pTerm = pid.pGain * error;
    pid.iState += error;
    pid.iState = (pid.iState > pid.iMax) ? pid.iMax: pid.iState;
    pid.iState = (pid.iState < pid.iMin) ? pid.iMin: pid.iState;
    iTerm = pid.iGain * pid.iState;
    dTerm = pid.dGain * (pid.dState - position);
    pid.dState = position;
    return pTerm + dTerm + iTerm;
}

int main() {
    PID state;

    for (int i = 0; i < 10; ++i) {
        std::cout << updatePID(state, 0.1, 0.5) << std::endl;
    }
}
