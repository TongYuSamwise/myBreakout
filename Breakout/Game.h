#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <algorithm>
#include <vector>

#include "game_level.h"

// ��������Ϸ�ĵ�ǰ״̬
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
// ��ʼ������Ĵ�С
const glm::vec2 PLAYER_SIZE(100, 20);
// ��ʼ�����������
const GLfloat PLAYER_VELOCITY(500.0f);
typedef std::tuple<GLboolean, Direction, glm::vec2> Collision;

class Game
{
public:
    // ��Ϸ״̬
    GameState  State;
    GLboolean  Keys[1024];
    GLuint     Width, Height;
    // �ؿ�
    std::vector<GameLevel> Levels;
    GLuint                 Level;
    // ���캯��/��������
    Game(GLuint width, GLuint height);
    ~Game();
    // ��ʼ����Ϸ״̬���������е���ɫ��/����/�ؿ���
    void Init();
    // ��Ϸѭ��
    void ProcessInput(GLfloat dt);
    void Update(GLfloat dt);
    void Render();
    void ResetPlayer();
    void ResetLevel();
    void DoCollisions();
};

