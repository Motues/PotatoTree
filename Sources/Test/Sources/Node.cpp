#include <Potato/Node.hpp>

using BT::NodeStatus;


namespace Potato :: Action {

NodeStatus AttackEnemy::tick() {
    std::cout << "AttackEnemy!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return NodeStatus :: SUCCESS;
}

NodeStatus CruiseAround::tick() {
    std::cout << "CruiseAround!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return NodeStatus :: SUCCESS;
}

NodeStatus GoHome::tick() {
    std::cout << "GoHome!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return NodeStatus :: SUCCESS;
}

NodeStatus TrackEnemy::tick() {
    std::cout << "TrackEnemy!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return NodeStatus :: SUCCESS;
}

}

namespace Potato :: Condition {
NodeStatus EnemyInAttackRange::tick() {
    std::cout << "EnemyInAttackRange!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return NodeStatus :: SUCCESS;
}

NodeStatus FindEnemy::tick() {
    std::cout << "FindEnemy!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return NodeStatus :: SUCCESS;
}

NodeStatus KnowLastPositionOfEnemy::tick() {
    std::cout << "KnowLastPositionOfEnemy!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return NodeStatus :: SUCCESS;
}

NodeStatus ConditionIsSafe::tick() {
    std::cout << "ConditionIsSafe!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return NodeStatus :: SUCCESS;
}


}
