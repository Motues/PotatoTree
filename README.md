# PatatoTree

本项目基于RoboMater比赛开发需求，构建一款可视化的智能决策工具，分为可视化应用和算法框架。

## 可视化应用

可视化应用通过在本地服务器搭建Web应用来实现，采取前后端分离框架，方便后期维护和多平台部署。  
整个项目使用`Node.js`完成，；前端使用`Vue CLI`，后端使用`Express.js`，前后端利用HTTPS完成通信。

项目使用`pnpm`管理。

## 算法框架

算法框架基于`C++`实现，OOP的设计思路。

## 数据存储

算法所需的树结构存储在JSON文件中，方便Web应用和C++程序处理。
