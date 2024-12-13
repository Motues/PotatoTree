#pragma once

#include "behaviortree_cpp/bt_factory.h"

using BT::NodeStatus;

namespace Potato :: Action {


using BT::SyncActionNode;

class AttackEnemy : public SyncActionNode {
public:
    AttackEnemy(const std::string& name) :
        SyncActionNode(name, {}) {}
    NodeStatus tick() override {
        std::cout << "AttackEnemy!" << std::endl;
        return NodeStatus::SUCCESS;
    }
};

class CruiseAround : public SyncActionNode {
public:
    CruiseAround(const std::string& name) :
        SyncActionNode(name, {}) {}
    NodeStatus tick() override {
        std::cout << "CruiseAround" << std::endl;
        return NodeStatus::SUCCESS;
    }
};

class GoHome : public SyncActionNode {
public:
    GoHome(const std::string& name) :
        SyncActionNode(name, {}) {}
    NodeStatus tick() override {
        std::cout << "GoHome!" << std::endl;
        return NodeStatus::SUCCESS;
    }
};

class TrackEnemy : public SyncActionNode {
public:
    TrackEnemy(const std::string& name) :
        SyncActionNode(name, {}) {}
    NodeStatus tick() override {
        std::cout << "TrackEnemy!" << std::endl;
        return NodeStatus::SUCCESS;
    }
};

}

namespace Potato :: Condition {

using BT::ConditionNode;

class ConditionIsSafe : public ConditionNode {
public:
    ConditionIsSafe(const std::string& name) :
        ConditionNode(name, {}) {}
    NodeStatus tick() override {
        std::cout << "ConditionIsSafe!" << std::endl;
        return NodeStatus::SUCCESS;
    }
};

class EnemyInAttackRange : public ConditionNode {
public:
    EnemyInAttackRange(const std::string& name) :
        ConditionNode(name, {}) {}
    NodeStatus tick() override {
        std::cout << "EnemyInAttackRange!" << std::endl;
        return NodeStatus::SUCCESS;
    }
};

class FindEnemy : public ConditionNode {
public:
    FindEnemy(const std::string& name) :
        ConditionNode(name, {}) {}
    NodeStatus tick() override {
        std::cout << "FindEnemy!" << std::endl;
        return NodeStatus::SUCCESS;
    }
};

class KnowLastPositionOfEnemy : public ConditionNode {
public:
    KnowLastPositionOfEnemy(const std::string& name) :
        ConditionNode(name, {}) {}
    NodeStatus tick() override {
        std::cout << "KnowLastPositionOfEnemy!" << std::endl;
        return NodeStatus::SUCCESS;
    }
};

}