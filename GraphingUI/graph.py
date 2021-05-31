import pygame
from cell import Cell
from assets import *

class Graph:
    #setup defaults for graph
    def __init__(self, length, width, cellColor):
        self.length = length
        self.width = width
        self.cellColor = cellColor
        #create an empty array of cells
        self.cells = []
        '''determine if the length or the width has more cells in it(because the grid is not always square) 
        so you can find what the size of the cell needs to be(because the cells are square)'''
        self.longestCellStrip = self.length if self.length > self.width else self.width
        #get the cell size by dividing the longest amount of cells in a row by the screens height
        self.cellSize = SCREEN_HEIGHT / self.longestCellStrip
        #fill the cell list
        self.createCells()

    def createCells(self):
        #Loop through the width and height
        for i in range(self.length):
            for j in range(self.width):
                # fill the cell array with correctly positioned cells for a grid
                self.cells.append(Cell(self.longestCellStrip, i * (SCREEN_WIDTH / self.longestCellStrip), j * (SCREEN_WIDTH / self.longestCellStrip), self.cellColor))
    
    def draw(self, screen):
        #draw each cell on its coords
        for cell in self.cells:
            cell.draw(screen)

        #draw thin black lines to seperate the cells
        for i in range(self.length):
            pygame.draw.line(screen, BLACK, (i * self.cellSize, 0), (i * self.cellSize, self.cellSize * self.width), width=1)
        for i in range(self.width + 1):
            pygame.draw.line(screen, BLACK, (0, i * self.cellSize), (SCREEN_WIDTH, i * self.cellSize), width=1)

    def clickCell(self, newColor, MousePos):
        #loop through each cell in the cell array and use its click function
        for cell in self.cells:
            if cell.clickCell(MousePos):
                #switch the cells color back and forth. (cell color can also be changed directly through the cells changeColor method if different behavior is needed)
                if cell.color == newColor:
                    cell.changeColor(self.cellColor)
                else:
                    cell.changeColor(newColor)