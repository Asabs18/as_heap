from assets import *
import pygame

pygame.init()

class Cell:
    #setup defaults for one cell in the grid
    def __init__(self, NumOfCells, x, y, color):
        self.color = color
        self.size = SCREEN_HEIGHT / NumOfCells
        self.coord = (x, y)
        self.rect = pygame.Rect(self.coord[0], self.coord[1], self.size, self.size)

    #draw one cell based on rectangle position and size
    def draw(self, screen):
        pygame.draw.rect(screen, self.color, self.rect)

    #change the cell color to whatever you want
    def changeColor(self, newColor):
        self.color = newColor

    #check one cells click against it rectangle
    def clickCell(self, MousePos):
        return self.rect.collidepoint(MousePos)
