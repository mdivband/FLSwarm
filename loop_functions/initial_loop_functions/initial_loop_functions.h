#ifndef INITIAL_LOOP_FUNCTIONS_H
#define INITIAL_LOOP_FUNCTIONS_H

#include <argos3/core/simulator/loop_functions.h>
#include <argos3/core/simulator/entity/floor_entity.h>
#include <argos3/core/utility/math/range.h>
#include <argos3/core/utility/math/rng.h>

using namespace argos;

class CInitialLoopFunctions : public CLoopFunctions {

public:
    
    CInitialLoopFunctions();
    virtual ~CInitialLoopFunctions() {}

    virtual void Init(TConfigurationNode& t_tree);
    virtual void Reset();
    virtual void Destory();
    virtual CColor GetFloorColor(const CVector2& c_position_on_plane); 
    
private:

    Real m_fObstacleRadius;
    CRange<Real> m_cInitialArenaSideX, m_cInitialArenaSideY;
    std::vector<CVector2> m_cObstaclePos;
    CFloorEntity* m_pcFloor;
    CRandom::CRNG* m_pcRNG;

    std::string m_strOutput;
    std::ofstream m_cOutput;

    UInt32 m_unCollectedObstacle;
    
};

#endif
