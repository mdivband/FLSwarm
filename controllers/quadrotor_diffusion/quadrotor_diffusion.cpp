#include "quadrotor_diffusion.h"
#include <argos3/core/utility/configuration/argos_configuration.h>
#include <argos3/core/utility/math/vector3.h>

CQuadRotorDiffusion::CQuadRotorDiffusion() :
    quad_actuator(NULL)
    // quad_tactuator(NULL) 
    {}

void CQuadRotorDiffusion::Init(TConfigurationNode& t_node) {
    // quad_tactuator = GetActuator<CCI_QuadRotorSpeedActuator> ("quadrotor_speed"); 
    quad_actuator = GetActuator<CCI_QuadRotorPositionActuator> ("quadrotor_position");
}

void CQuadRotorDiffusion::ControlStep() {
	
}

REGISTER_CONTROLLER(CQuadRotorDiffusion, "quadrotor_diffusion_controller")    
