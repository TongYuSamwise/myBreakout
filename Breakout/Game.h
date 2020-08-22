#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <algorithm>
#include <vector>

#include "game_level.h"

// 代表了游戏的当前状态
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

// Collision Direction
enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};
// Initial velocity of the Ball
const glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);
// Radius of the ball object
const float BALL_RADIUS = 12.5f;
// 初始化挡板的大小
const glm::vec2 PLAYER_SIZE(100, 20);
// 初始化当班的速率
const GLfloat PLAYER_VELOCITY(500.0f);
typedef std::tuple<GLboolean, Direction, glm::vec2> Collision;

class Game
{
public:
    // 游戏状态
    GameState  State;
    GLboolean  Keys[1024];
    GLuint     Width, Height;
    // 关卡
    std::vector<GameLevel> Levels;
    GLuint                 Level;
    // 构造函数/析构函数
    Game(GLuint width, GLuint height);
    ~Game();
    // 初始化游戏状态（加载所有的着色器/纹理/关卡）
    void Init();
    // 游戏循环
    void ProcessInput(GLfloat dt);
    void Update(GLfloat dt);
    void Render();
    void ResetPlayer();
    void ResetLevel();
    void DoCollisions();
};

