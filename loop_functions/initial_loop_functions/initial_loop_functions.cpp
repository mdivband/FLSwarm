#include "initial_loop_functions.h"
#include <argos3/core/simulator/simulator.h>
#include <argos3/core/utility/configuration/argos_configuration.h>
#include <argos3/plugins/robots/foot-bot/simulator/footbot_entity.h>
#include <controllers/footbot_foraging/footbot_foraging.h>

CInitialLoopFunctions::CInitialLoopFunctions() :
    m_cInitialArenaSideX(-0.9f, 1.7f),
    m_cInitialArenaSideY(-1.7f, 1.7f),
    m_pcFloor(NULL),
    m_pcRNG(NULL) {}

void CInitialLoopFunctions::Init(TConfigurationNode& t_node) {
   try {
      TConfigurationNode& tInitial = GetNode(t_node, "foraging");
      /* Get a pointer to the floor entity */
      m_pcFloor = &GetSpace().GetFloorEntity();
      /* Get the number of food items we want to be scattered from XML */
      UInt32 unObstacleItems;
      GetNodeAttribute(tInitial, "items", unObstacleItems);
      /* Get the number of food items we want to be scattered from XML */
      GetNodeAttribute(tInitial, "radius", m_fObstacleRadius);
      m_fObstacleRadius *= m_fObstacleRadius;
      /* Get the output file name from XML */
      GetNodeAttribute(tInitial, "output", m_strOutput);
      /* Open the file, erasing its contents */
      m_cOutput.open(m_strOutput.c_str(), std::ios_base::trunc | std::ios_base::out);
      m_cOutput << "Example Output" << std::endl;
   }
   catch(CARGoSException& ex) {
      THROW_ARGOSEXCEPTION_NESTED("Error parsing loop functions!", ex);
   }
}	

void CInitialLoopFunctions::Reset() {
   /* Zero the counters */
   m_unCollectedObstacle = 0;
   /* Close the file */
   m_cOutput.close();
   /* Open the file, erasing its contents */
   m_cOutput.open(m_strOutput.c_str(), std::ios_base::trunc | std::ios_base::out);
   m_cOutput << "Example Reset Output" << std::endl;
}

void CInitialLoopFunctions::Destory() {
    /* Close the file. */
    m_cOutput.close();
}

CColor CInitialLoopFunctions::GetFloorColor(const CVector2& c_position_on_plane) {
   if(c_position_on_plane.GetX() < -1.0f) {
      return CColor::GRAY50;
   }
   for(UInt32 i = 0; i < m_cObstaclePos.size(); ++i) {
      if((c_position_on_plane - m_cObstaclePos[i]).SquareLength() < m_fObstacleRadius) {
         return CColor::BLACK;
      }
   }
   return CColor::WHITE;
}

REGISTER_LOOP_FUNCTIONS(CInitialLoopFunctions, "initial_loop_functions")
