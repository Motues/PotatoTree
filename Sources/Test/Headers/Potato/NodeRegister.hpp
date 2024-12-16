#pragma once

#include <Potato/Node.hpp>

namespace Potato {


#define REGISTER_NODES(NodeName, NodeType) \
    factory.registerNodeType<NodeType::NodeName>(#NodeName);
void registerNodes(BT::BehaviorTreeFactory& factory){
    // Register your nodes here
    // Action Nodes
    REGISTER_NODES(AttackEnemy, Action);
    REGISTER_NODES(CruiseAround, Action);
    REGISTER_NODES(GoHome, Action);
    REGISTER_NODES(TrackEnemy, Action);

    // Condition Nodes
    REGISTER_NODES(ConditionIsSafe, Condition);
    REGISTER_NODES(EnemyInAttackRange, Condition);
    REGISTER_NODES(FindEnemy, Condition);
    REGISTER_NODES(KnowLastPositionOfEnemy, Condition);
}

}