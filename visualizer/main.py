import pygame
import json
import sys
from pathlib import Path



BASE_DIR = Path(__file__).resolve().parent
json_path = BASE_DIR.parent / "simulation.json"


def loadSimulation(path):
    with open(path, 'r') as f:
        data = json.load(f)
    return data["frames"]

def world_to_screen(x, y, screen_width, screen_height, scale):
    screen_x = screen_width / 2 + x * scale
    screen_y = screen_height /2 - y * scale
    return screen_x, screen_y

def draw_frame(screen, frame_data, scale):
    
    width, height = screen.get_size()
    
    for atom in frame_data["fuel_atoms"]:
        x,y = world_to_screen(
                atom["x"],
                atom["y"],
                width,
                height,
                scale
            )
        
        
        if atom["consumed"]:
            color = (120,120,120)
        else:
            color = (0,255,0)
        
        pygame.draw.circle(screen, color, (int(x), int(y)), 5)
        
    for neutron in frame_data["neutrons"]:
        x,y =world_to_screen(
                neutron["x"],
                neutron["y"],
                width,
                height,
                scale
            )
        
        pygame.draw.circle(screen, (255,0,0), (int(x), int(y)), 3)
    
    
def main():
    pygame.init()
    screen = pygame.display.set_mode((800, 600))
    clock = pygame.time.Clock()
    
    frames = loadSimulation(json_path)
    current_frame = 0
    
    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
                
        screen.fill((0,0,0))
        draw_frame(screen, frames[current_frame], scale=10)
        pygame.display.flip()
        
        current_frame = (current_frame + 1) % len(frames)
        clock.tick(5)
        
    pygame.quit()
    sys.exit()
    
if __name__ == "__main__":
    main()