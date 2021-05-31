import pygame, sys
from assets import *
from graph import Graph

'''
Example driver code to show off the ease and use of the graph class
'''

#setup pygame
pygame.init()
screen = pygame.display.set_mode((0, 0), pygame.FULLSCREEN)
clock = pygame.time.Clock()
pygame.display.set_caption("Graph")

#create graph
graph = Graph(500, 500, DARKGREY)

#start game loop
while True:
    clock.tick(FPS)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_q:
                pygame.quit()
                sys.exit()
        #check for mouse events. if mouse events are found run the graphs click function to narrow in on the cell
        if event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
            graph.clickCell(WHITE, pygame.mouse.get_pos())

    #draw the screen
    screen.fill(DARKGREY)
    graph.draw(screen) #draw the graph itself
    pygame.display.flip()