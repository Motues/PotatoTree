#pragma once

#include <Potato/Node.hpp>

namespace Potato {

void registerNodes(BT::BehaviorTreeFactory& factory){
    // Register your nodes here
    factory.registerNodeType<AttackEnemy>("AttackEnemy");
    factory.registerNodeType<ConditionIsSafe>("ConditionIsSafe");
    factory.registerNodeType<CruiseAround>("CruiseAround");
    factory.registerNodeType<EnemyInAttackRange>("EnemyInAttackRange");
    factory.registerNodeType<FindEnemy>("FindEnemy");
    factory.registerNodeType<GoHome>("GoHome");
    factory.registerNodeType<KnowLastPositionOfEnemy>("KnowLastPositionOfEnemy");
    factory.registerNodeType<TrackEnemy>("TrackEnemy");
}

}