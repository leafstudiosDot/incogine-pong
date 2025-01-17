//
//  game.cpp
//  Incogine
//
//  Created by moritz on 10/17/22.
//

#include "game.hpp"

Game::Game() {
    // Initialize Game
    Console console;
    console.Println("Game initialized successfully");
}

Game::~Game() {
    // Purge Game
    Console console;
    console.Println("Game purged successfully");
}

float playery = 300, speed = 10;
float player2y = 300;
float ballx = 625, bally = 365, ballspeed = 7;
const Uint8 *_Pkeyboard = SDL_GetKeyboardState(0);


void Game::RawEvent(SDL_Event event, int _windowWidth, int _windowHeight) {
    // Events (Keyboard, Mouse, etc.)
    Console console;
    
    // Type-Style KeyDown (Hold Key)
    /*if (_Pkeyboard[SDL_SCANCODE_D]) {
        // Pressed
        playerx += speed;
    } else {
        // Released
    }
    
    if (_Pkeyboard[SDL_SCANCODE_A]) {
       // Pressed
        console.Println("Type Style Left Key Pressed");
        playerx -= speed;
    } else {
        // Released
    }*/

    if (_Pkeyboard[SDL_SCANCODE_W]) {
        // Pressed
        playery -= speed;
    } else {
        // Released
    }
    
    if (_Pkeyboard[SDL_SCANCODE_S]) {
        // Pressed
        playery += speed;
    } else {
        // Released
    }
}

void Game::Event(SDL_Event event) {
    Console console;
    
    // Quit
    if(event.type == SDL_QUIT) {
        Core::corerunning = false;
    }
    
    // KeyUp and KeyDown
    // Pressed
    if(event.type == SDL_KEYDOWN) {
        switch(event.key.keysym.sym){
        case SDLK_LEFT:
            console.Println("Left Key Pressed");
            break;
        }
    }
    // Released
    if(event.type == SDL_KEYUP) {
        switch(event.key.keysym.sym) {
            case SDLK_LEFT:
                console.Println("Left Key Lifted");
                break;
        }
    }
}

void Game::Start() {
    // Executes as game launches
    Console console;
}

void Game::Update(int _windowWidth, int _windowHeight) {
    // Executes every frame at game
    
    if (playery >= 615) {
        playery = 615;
    } else if (playery <= 5) {
        playery = 5;
    }
}

void Game::Render() {
    // Render Game
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    
    // Border Top
    glPushMatrix();
    glTranslated(0, 0, 0);
    glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0, 0);
        glVertex2f(1280, 0);
        glVertex2f(1280, 5);
        glVertex2f(0, 5);
    glEnd();
    glPopMatrix();
    
    // Border Bottom
    glPushMatrix();
    glTranslated(0, 0, 0);
    glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0, 720);
        glVertex2f(1280, 720);
        glVertex2f(1280, 715);
        glVertex2f(0, 715);
    glEnd();
    glPopMatrix();
    
    // Player 1
    glPushMatrix();
    glTranslated(0, playery, 0);
    glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0, 0);
        glVertex2f(25, 0);
        glVertex2f(25, 100);
        glVertex2f(0, 100);
    glEnd();
    glPopMatrix();
    
    // Ball
    glPushMatrix();
    glTranslated(ballx, bally, 0);
    glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0, 0);
        glVertex2f(15, 0);
        glVertex2f(15, 15);
        glVertex2f(0, 15);
    glEnd();
    glPopMatrix();
    
    // Player 2
    glPushMatrix();
    glTranslated(1280-25, player2y, 0);
    glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0, 0);
        glVertex2f(25, 0);
        glVertex2f(25, 100);
        glVertex2f(0, 100);
    glEnd();
    glPopMatrix();
}
