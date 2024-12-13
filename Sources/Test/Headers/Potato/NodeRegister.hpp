#pragma once

#include <Potato/Node.hpp>

namespace Potato {

void registerNodes(BT::BehaviorTreeFactory& factory){
    // Register your nodes here
    // Action Nodes
    factory.registerNodeType<Action::AttackEnemy>("AttackEnemy");
    factory.registerNodeType<Action::CruiseAround>("CruiseAround");
    factory.registerNodeType<Action::GoHome>("GoHome");
    factory.registerNodeType<Action::TrackEnemy>("TrackEnemy");

    // Condition Nodes
    factory.registerNodeType<Condition::ConditionIsSafe>("ConditionIsSafe");
    factory.registerNodeType<Condition::EnemyInAttackRange>("EnemyInAttackRange");
    factory.registerNodeType<Condition::FindEnemy>("FindEnemy");
    factory.registerNodeType<Condition::KnowLastPositionOfEnemy>("KnowLastPositionOfEnemy");
}

}