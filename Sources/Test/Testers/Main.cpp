#include <iostream>
#include <Potato/NodeRegister.hpp>
#include "behaviortree_cpp/loggers/bt_file_logger_v2.h"
#include "behaviortree_cpp/loggers/bt_cout_logger.h"
#include "behaviortree_cpp/loggers/groot2_publisher.h"
#include "behaviortree_cpp/loggers/bt_minitrace_logger.h"


using BT::BehaviorTreeFactory;
using BT::FileLogger2;
using BT::StdCoutLogger;
using BT::Groot2Publisher;
using BT::MinitraceLogger;
using namespace Potato;
int main() {
    BehaviorTreeFactory factory;
    registerNodes(factory);
    auto tree = factory.createTreeFromFile("../../Groot/Test/Fight.xml");
    // 创建日志文件路径
    std::filesystem::path logFilePath = "../../Groot/Log/fight_log.btlog";

    // 创建 FileLogger2 实例
    FileLogger2 logger(tree, logFilePath);
    // StdCoutLogger logger(tree);
    // Groot2Publisher logger(tree, 5555);
    // MinitraceLogger logger(tree, "../../Groot/Log/fight_log.json");
    while(true) {
        std::cout << "Starting tree tick...\n";
        tree.tickWhileRunning();
        std::cout << "Tree tick finished.\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    
    return 0;
}