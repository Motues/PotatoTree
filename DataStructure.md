# 数据传输格式

比赛兵种代号和红蓝方参考`ly.app\modules\ly.common\include\ly\robomaster\unit_type.hpp`

```c++
/// @brief 单位类型
enum class UnitType : std::uint8_t
{
	Unknown   = 0,
	Hero      = Unknown + 1,
	Engineer  = Hero + 1,
	Infantry1 = Engineer + 1,
	Infantry2 = Infantry1 + 1,
	Infantry3 = Infantry2 + 1,
	Drone     = Infantry3 + 1,
	Sentry    = Drone + 1,
	Dart	  = Sentry + 1,
	Radar     = Dart + 1
};

/// @brief 团队类型
enum class UnitTeam : std::uint8_t
{
	Unknown = 0,
	Red     = Unknown + 1,
	Blue    = Red + 1,
	Other   = Blue + 1
};
```

## 辅瞄

* From：当前目标的云台角度，视野中的装甲板序列
* To: 击打目标

```c++
/// 辅瞄返回数据
struct autoaim_data {
    struct armor_data {
        UnitType type; // 装甲板类型
        uint8_t distance; // 距离
    }
    std::array<float, 2> angles; // 云台角度
    std::array<armor_data, 5> armor_list; // 装甲板序列
}
```

```c++
/// 辅瞄接收数据
struct autoaim_target_data {
    UnitType target; // 击打目标
}

```

## 导航

* From: 目标点位，追击状态
* To: 地盘速度，特殊地点预警信号


```c++
/// 导航接收数据
struct navigation_data {
    std::uint8_t destinationID; // 目标点位
    bool tarck_code; // 追击状态
}
```

```c++
/// 导航返回数据
struct navigation_target_data {
    std::array<float, 2> velocity; // 底盘速度
    bool warning_code; // 特殊地点预警信号
}
```


```c++
/// 点位代号
struct TeamedLocation {
	static constexpr auto LocationCount = 9;

	std::uint8_t ID;

	std::uint8_t operator()(const UnitTeam team) const {
		return team == UnitTeam::Blue ? ID + LocationCount : ID;
	}
};
static constexpr TeamedLocation Home{0};
static constexpr TeamedLocation Outpost{1};
static constexpr TeamedLocation High{2};
static constexpr TeamedLocation Recovery{3};
static constexpr TeamedLocation Fly{4};
static constexpr TeamedLocation CoverShoot{5};
static constexpr TeamedLocation Resource{7};
static constexpr TeamedLocation EasyOres{8};

```

## 下位机

* From: 云台数据（开火状态，云台角度），比赛数据
* To: 上位机云台控制数据


```c++
/// 云台返回数据
struct gimbal_data {
    static constexpr auto message_id = 0; // 表示云台数据
    std::array<float, 3> angles; // 云台欧拉角
    std::array<std::int8_t, 2> velocity; // 底盘速度
    fire_code_type fire_code; // 开火状态
};

/// 开火状态
struct fire_code_type {
    std::uint8_t last_fire_status : 2 = 0; // 上次开火状态，状态翻转表示开火
    std::uint8_t friction_wheel : 2 = 0; // 摩擦轮状态
    std::uint8_t fire_rate : 2 = 0; // 发射频率
    std::uint8_t maneuver : 2 = 0; // 人工操作
    void flip_fire_status() noexcept {
        last_fire_status = last_fire_status == 0b00 ? 0b11 : 0b00;
    }
}
```

```c++
/// 比赛数据
struct game_data {
    static constexpr auto message_id = 1; // 表示比赛数据
    game_code_type game_code; // 比赛状态
    std::uint16_t ammo_left{}; // 允许发弹量
    std::uint16_t time_left{};  // 剩余时间
    std::uint16_t my_hp{}; // 血量
    uwb_position position{}; // 位置
    std::array<std::uint8_t, 3> padding_bytes{}; // 填充字节
};

using uwb_position = std::array<std::int16_t, 2>;

struct game_code_type {
    std::uint16_t is_game_begin : 1 = 0; // 比赛开始状态
    std::uint16_t is_hero_precaution : 1 = 0; // 英雄预警信息
    std::uint16_t is_my_team_red : 1 = 0; // 队伍颜色
    std::uint16_t enemy_outpost_health : 6 = 0; // 敌方哨站血量
    std::uint16_t self_outpost_health : 6 = 0; // 己方哨站血量
    std::uint16_t is_returned_home : 1 = 0; // 回归基地状态
};
```

```c++
/// 下位机接收控制数据
struct control_data {
    static constexpr auto message_id = 2; // 表示上位机控制云台数据
    std::array<float, 2> angles; // 云台角度，pitch yaw
    std::array<std::int8_t, 2> velocity;// 底盘速度
    fire_code_type fire_code; // 开火状态
    bool warning_code; // 通过特殊地形状态
};
```

## 雷达

