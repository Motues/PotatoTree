#pragma once

#include "behaviortree_cpp/bt_factory.h"

using BT::NodeStatus;

namespace Potato :: Action {


using BT::SyncActionNode;

class AttackEnemy : public SyncActionNode {
public:
    AttackEnemy(const std::string& name) :
        SyncActionNode(name, {}) {}
    
    NodeStatus tick(); // NodeStatus tick() override {}
};

class CruiseAround : public SyncActionNode {
public:
    CruiseAround(const std::string& name) :
        SyncActionNode(name, {}) {}
    NodeStatus tick(); // NodeStatus tick() override {}
};

class GoHome : public SyncActionNode {
public:
    GoHome(const std::string& name) :
        SyncActionNode(name, {}) {}
    NodeStatus tick(); // NodeStatus tick() override {}
};

class TrackEnemy : public SyncActionNode {
public:
    TrackEnemy(const std::string& name) :
        SyncActionNode(name, {}) {}
    NodeStatus tick(); // NodeStatus tick() override {}
};

}

namespace Potato :: Condition {

using BT::ConditionNode;

class ConditionIsSafe : public ConditionNode {
public:
    ConditionIsSafe(const std::string& name) :
        ConditionNode(name, {}) {}
    NodeStatus tick(); // NodeStatus tick() override {}
};

class EnemyInAttackRange : public ConditionNode {
public:
    EnemyInAttackRange(const std::string& name) :
        ConditionNode(name, {}) {}
    NodeStatus tick(); // NodeStatus tick() override {}
};

class FindEnemy : public ConditionNode {
public:
    FindEnemy(const std::string& name) :
        ConditionNode(name, {}) {}
    NodeStatus tick(); // NodeStatus tick() override {}
};

class KnowLastPositionOfEnemy : public ConditionNode {
public:
    KnowLastPositionOfEnemy(const std::string& name) :
        ConditionNode(name, {}) {}
    NodeStatus tick(); // NodeStatus tick() override {}
};

}