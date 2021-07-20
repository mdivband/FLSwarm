/*
 * AUTHOR: Ali Yamini 
 *
 * This is the quadrotor controller to create the collision avoidance effect.
*/ 

#ifndef QUADROTOR_DIFFUSION_H
#define QUADROTOR_DIFFUSION_H

#include <argos3/core/control_interface/ci_controller.h>
#include <argos3/plugins/robots/generic/control_interface/ci_quadrotor_position_actuator.h>
#include <argos3/plugins/robots/generic/control_interface/ci_quadrotor_speed_actuator.h>

using namespace argos;

class CQuadRotorDiffusion : public CCI_Controller {

public:
	
    CQuadRotorDiffusion();

    virtual ~CQuadRotorDiffusion() {}
    
    virtual void Init(TConfigurationNode& t_node); 

    virtual void ControlStep();

    virtual void Reset() {}

    virtual void Destory() {}

private:

    CCI_QuadRotorPositionActuator* quad_actuator;
    // CCI_QuadRotorSpeedActuator* quad_tactuator;
    
};

#endif
