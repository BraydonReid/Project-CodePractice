import pygame

pygame.init()

WIDTH = 1000
HEIGHT = 900

screen = pygame.display.set_mode([WIDTH, HEIGHT])
front = pygame.font.Font('freesansbold.ttf', 20)
big_font = pygame.font.Font("freesansbold.ttf", 50)
timer = pygame.time.Clock()
fps = 60
# Variables and Images
white_pieces = ['rook', 'knight', 'bishop', 'king','queen', 'bishop', 'knight', 'rook',
                'pawn','pawn','pawn','pawn','pawn','pawn','pawn','pawn' ]

white_locations = [(0,0),(1,0),(2,0),(3,0),(4,0),(5,0),(6,0),(7,0),
                   (0,1),(1,1),(2,1),(3,1),(4,1),(5,1),(6,1),(7,1)]

black_locations = [(0,7),(1,7),(2,7),(3,7),(4,7),(5,7),(6,7),(7,7),
                   (0,6),(1,6),(2,6),(3,6),(4,6),(5,6),(6,6),(7,6)]

black_pieces = ['rook', 'knight', 'bishop', 'king','queen', 'bishop', 'knight', 'rook',
                'pawn','pawn','pawn','pawn','pawn','pawn','pawn','pawn' ]

captured_pieces_white = []

captured_pieces_black = []

##############################################################################################################################

# 0 --white turn no selection: 1 --white turn piece selected: 2 --black turn no selection: 3 --black turn piece selected
turn_step = 0
selection = 100

valid_moves = []

##############################################################################################################################

#Game piece images loaded

#Black
def load_and_scale(image_path, size, small_size):
    image = pygame.image.load(image_path)
    return pygame.transform.scale(image, size), pygame.transform.scale(image, small_size)

# Black pieces
black_queen, black_queen_small = load_and_scale('assets/images/black queen.png', (80, 80), (45, 45))
black_king, black_king_small = load_and_scale('assets/images/black king.png', (80, 80), (45, 45))
black_rook, black_rook_small = load_and_scale('assets/images/black rook.png', (80, 80), (45, 45))
black_bishop, black_bishop_small = load_and_scale('assets/images/black bishop.png', (80, 80), (45, 45))
black_knight, black_knight_small = load_and_scale('assets/images/black knight.png', (80, 80), (45, 45))
black_pawn, black_pawn_small = load_and_scale('assets/images/black pawn.png', (65, 65), (45, 45))

black_images = [black_pawn, black_queen, black_king, black_knight, black_rook, black_bishop]
small_black_images = [black_pawn_small, black_queen_small, black_king_small, black_knight_small,black_rook_small, black_bishop_small]

# White pieces
white_queen, white_queen_small = load_and_scale('assets/images/white queen.png', (80, 80), (45, 45))
white_king, white_king_small = load_and_scale('assets/images/white king.png', (80, 80), (45, 45))
white_rook, white_rook_small = load_and_scale('assets/images/white rook.png', (80, 80), (45, 45))
white_bishop, white_bishop_small = load_and_scale('assets/images/white bishop.png', (80, 80), (45, 45))
white_knight, white_knight_small = load_and_scale('assets/images/white knight.png', (80, 80), (45, 45))
white_pawn, white_pawn_small = load_and_scale('assets/images/white pawn.png', (65, 65), (45, 45))

white_images = [white_pawn, white_queen, white_king, white_knight, white_rook, white_bishop]
small_white_images = [white_pawn_small, white_queen_small, white_king_small, white_knight_small, white_rook_small, white_bishop_small]


piece_list = ['pawn', 'queen', 'king', 'knight', 'rook', 'bishop']



#Check Variables
winner = ''
game_over = False


#Draw Game Board
def draw_board():
    for i in range (32):
        column = i % 4
        row = i // 4
        if row % 2 == 0:
            pygame.draw.rect(screen, 'light gray', [600 - (column * 200), row * 100, 100, 100])
        else: 
            pygame.draw.rect(screen, 'light gray', [700 - (column * 200), row * 100, 100, 100])

        pygame.draw.rect(screen, 'gray', [0,800, WIDTH, 100])
        pygame.draw.rect(screen, 'red', [0,800, WIDTH, 100], 5)
        pygame.draw.rect(screen, 'red', [800,0, 200, HEIGHT], 5)

        status_text = ['White: Select a Piece to Move!', 'White: Move Your Piece',
                        'Black: Select a Piece to Move!', 'Black: Move Your Piece']
        
        screen.blit(big_font.render(status_text[turn_step], True, 'black'), (20, 820))

        for i in range(9):
            pygame.draw.line(screen, 'black', (0, 100 * i), (800, 100 * i), 2)
            pygame.draw.line(screen, 'black', (100 * i, 0), (100 * i, 800), 2)


#Draws the Pieces onto the board
def draw_pieces():
    for i in range (len(white_pieces)):
        index = piece_list.index(white_pieces[i])
        if white_pieces[i] == 'pawn':
            screen.blit(white_pawn, (white_locations[i][0]* 100 + 22, white_locations[i][1] * 100 + 30))
        else: 
            screen.blit(white_images[index], (white_locations[i][0]* 100 + 10, white_locations[i][1] * 100 + 10))
        if turn_step < 2:
            if selection == i:
                pygame.draw.rect(screen, 'yellow', [white_locations[i][0] * 100 + 1, white_locations[i][1] * 100 + 1,
                                                    100, 100], 2)


    for i in range (len(black_pieces)):
        index = piece_list.index(black_pieces[i])
        if black_pieces[i] == 'pawn':
            screen.blit(black_pawn, (black_locations[i][0]* 100 + 22, black_locations[i][1] * 100 + 30))
        else: 
            screen.blit(black_images[index], (black_locations[i][0]* 100 + 10, black_locations[i][1] * 100 + 10))
        if turn_step < 2:
            if selection == i:
                pygame.draw.rect(screen, 'green', [black_locations[i][0] * 100 + 1, black_locations[i][1] * 100 + 1,
                                                    100, 100], 2)

#checks all valid options to move
# Checks all valid options to move for each piece type
def check_options(pieces, locations, turn):
    moves_list = []
    all_moves_list = []

    for i in range(len(pieces)):
        location = locations[i]
        piece = pieces[i]

        if piece == 'pawn':
            moves_list = check_pawn(location, turn)
        elif piece == 'rook':
            moves_list = check_rook(location, turn)
        elif piece == 'knight':
            moves_list = check_knight(location, turn)
        elif piece == 'bishop':
            moves_list = check_bishop(location, turn)
        elif piece == 'queen':
            moves_list = check_queen(location, turn)
        elif piece == 'king':
            moves_list = check_king(location, turn)

        all_moves_list.append(moves_list)

    return all_moves_list



#checks pawn moves
def check_pawn(position,  color):
    moves_list =[]
    if color == 'white':
        if (position[0], position[1] + 1) not in white_locations and \
             (position[0], position[1] + 1) not in white_locations and position[1] < 7:
            moves_list.append((position[0], position[1] + 1))
        if (position[0], position[1] + 2) not in white_locations and \
             (position[0], position[1] + 2) not in white_locations and position[1] == 1:
            moves_list.append((position[0], position[1] + 2))
        if (position[0] + 1, position[1] + 1) in black_locations:
            moves_list.append((position[0] + 1, position[1] + 1))
        if (position[0] - 1, position[1] + 1) in black_locations:
            moves_list.append((position[0] - 1, position[1] + 1))
    #if black
    else:
        if (position[0], position[1] - 1) not in white_locations and \
             (position[0], position[1] - 1) not in white_locations and position[1] > 0:
            moves_list.append((position[0], position[1] - 1))
        if (position[0], position[1] - 2) not in white_locations and \
             (position[0], position[1] - 2) not in white_locations and position[1] == 6:
            moves_list.append((position[0], position[1] - 2))
        if (position[0] + 1, position[1] - 1) in white_locations:
            moves_list.append((position[0] + 1, position[1] - 1))
        if (position[0] - 1, position[1] - 1) in white_locations:
            moves_list.append((position[0] - 1, position[1] - 1))


    return moves_list

def check_rook(position, color):
    moves_list = []

    # Check horizontal and vertical moves
    for x in range(1, 8):
        # Right
        if (position[0] + x, position[1]) not in white_locations and \
                (position[0] + x, position[1]) not in black_locations and position[0] + x <= 7:
            moves_list.append((position[0] + x, position[1]))
        elif (position[0] + x, position[1]) in (white_locations if color == 'black' else black_locations):
            moves_list.append((position[0] + x, position[1]))
            break
        else:
            break

    for x in range(1, 8):
        # Left
        if (position[0] - x, position[1]) not in white_locations and \
                (position[0] - x, position[1]) not in black_locations and position[0] - x >= 0:
            moves_list.append((position[0] - x, position[1]))
        elif (position[0] - x, position[1]) in (white_locations if color == 'black' else black_locations):
            moves_list.append((position[0] - x, position[1]))
            break
        else:
            break

    for y in range(1, 8):
        # Down
        if (position[0], position[1] + y) not in white_locations and \
                (position[0], position[1] + y) not in black_locations and position[1] + y <= 7:
            moves_list.append((position[0], position[1] + y))
        elif (position[0], position[1] + y) in (white_locations if color == 'black' else black_locations):
            moves_list.append((position[0], position[1] + y))
            break
        else:
            break

    for y in range(1, 8):
        # Up
        if (position[0], position[1] - y) not in white_locations and \
                (position[0], position[1] - y) not in black_locations and position[1] - y >= 0:
            moves_list.append((position[0], position[1] - y))
        elif (position[0], position[1] - y) in (white_locations if color == 'black' else black_locations):
            moves_list.append((position[0], position[1] - y))
            break
        else:
            break

    return moves_list

def check_knight(position, color):
    moves_list = []
    knight_moves = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]

    for move in knight_moves:
        new_pos = (position[0] + move[0], position[1] + move[1])
        if 0 <= new_pos[0] <= 7 and 0 <= new_pos[1] <= 7:
            if new_pos not in (white_locations if color == 'white' else black_locations):
                moves_list.append(new_pos)

    return moves_list

def check_bishop(position, color):
    moves_list = []

    for i in range(1, 8):
        # Top-right diagonal
        if (position[0] + i, position[1] - i) not in white_locations and \
                (position[0] + i, position[1] - i) not in black_locations and position[0] + i <= 7 and position[1] - i >= 0:
            moves_list.append((position[0] + i, position[1] - i))
        elif (position[0] + i, position[1] - i) in (white_locations if color == 'black' else black_locations):
            moves_list.append((position[0] + i, position[1] - i))
            break
        else:
            break

    for i in range(1, 8):
        # Top-left diagonal
        if (position[0] - i, position[1] - i) not in white_locations and \
                (position[0] - i, position[1] - i) not in black_locations and position[0] - i >= 0 and position[1] - i >= 0:
            moves_list.append((position[0] - i, position[1] - i))
        elif (position[0] - i, position[1] - i) in (white_locations if color == 'black' else black_locations):
            moves_list.append((position[0] - i, position[1] - i))
            break
        else:
            break

    for i in range(1, 8):
        # Bottom-right diagonal
        if (position[0] + i, position[1] + i) not in white_locations and \
                (position[0] + i, position[1] + i) not in black_locations and position[0] + i <= 7 and position[1] + i <= 7:
            moves_list.append((position[0] + i, position[1] + i))
        elif (position[0] + i, position[1] + i) in (white_locations if color == 'black' else black_locations):
            moves_list.append((position[0] + i, position[1] + i))
            break
        else:
            break

    for i in range(1, 8):
        # Bottom-left diagonal
        if (position[0] - i, position[1] + i) not in white_locations and \
                (position[0] - i, position[1] + i) not in black_locations and position[0] - i >= 0 and position[1] + i <= 7:
            moves_list.append((position[0] - i, position[1] + i))
        elif (position[0] - i, position[1] + i) in (white_locations if color == 'black' else black_locations):
            moves_list.append((position[0] - i, position[1] + i))
            break
        else:
            break

    return moves_list


#checks queen moves (combines rook and bishop)
def check_queen(position, color):
    return check_rook(position, color) + check_bishop(position, color)

def check_king(position, color):
    moves_list = []
    king_moves = [(1, 1), (1, -1), (-1, 1), (-1, -1), (1, 0), (-1, 0), (0, 1), (0, -1)]

    for move in king_moves:
        new_pos = (position[0] + move[0], position[1] + move[1])
        if 0 <= new_pos[0] <= 7 and 0 <= new_pos[1] <= 7:
            if new_pos not in (white_locations if color == 'white' else black_locations):
                moves_list.append(new_pos)

    return moves_list


def check_valid_moves():
    try:
        if turn_step < 2:
            options_list = white_options
        else:
            options_list = black_options

        if 0 <= selection < len(options_list):
            valid_options = options_list[selection]
        else:
            valid_options = []  

    except IndexError:
        print(f"Invalid selection index: {selection}. No valid moves available.")
        valid_options = []

    return valid_options



def draw_valid(moves):
    if turn_step < 2:
        color = 'yellow'
    else: 
        color = 'green'
    for i in range(len(moves)):
        pygame.draw.circle(screen, color, (moves[i][0] * 100 + 50, moves[i][1] * 100 + 50), 5)
    

def check_for_check(king_position, color, opponent_pieces, opponent_locations):
    for i in range(len(opponent_locations)):
        opponent = opponent_pieces[i]
        opponent_moves = check_options([opponent], [opponent_locations[i]], color)
        if king_position in opponent_moves[0]:
            return True
    return False

def taken_pieces():
    for i in range(len(captured_pieces_white)):
        screen.blit(small_black_images[piece_list.index(captured_pieces_white[i])], (810, 5 + 50 * i))
    for i in range(len(captured_pieces_black)):
        screen.blit(small_white_images[piece_list.index(captured_pieces_black[i])], (900, 5 + 50 * i))
    

def draw_check():
    if turn_step < 2:
        if 'king' in white_pieces:
            king_index = white_pieces.index('king')
            king_location = white_locations[king_index]
            for i in range(len(black_options)):
                if king_location in black_options[i]:
                    pygame.draw.rect(screen, 'dark red', [white_locations[king_index][0] * 100 + 1,
                                                              white_locations[king_index][1] * 100 + 1, 100, 100], 5)
    else:
        if 'king' in black_pieces:
            king_index = black_pieces.index('king')
            king_location = black_locations[king_index]
            for i in range(len(white_options)):
                if king_location in white_options[i]:
                    pygame.draw.rect(screen, 'dark blue', [black_locations[king_index][0] * 100 + 1,
                                                               black_locations[king_index][1] * 100 + 1, 100, 100], 5)
                        
def draw_Game_Over():
    if 'king' not in white_pieces:
        screen.blit(big_font.render('Black Wins!', True, 'black'), (400, 400))
    if 'king' not in black_pieces:
        screen.blit(big_font.render('White Wins!', True, 'black'), (400, 400))
    pygame.display.flip()
    pygame.time.wait(5000)
    pygame.quit()
    quit()
    
def update_options():
    global black_options, white_options
    black_options = check_options(black_pieces, black_locations, 'black')
    white_options = check_options(white_pieces, white_locations, 'white')

def reset_game():
    global game_over, winner, white_pieces, white_locations, black_pieces, black_locations, captured_pieces_white, captured_pieces_black, turn_step, selection, valid_moves, black_options, white_options
    game_over = False
    winner = ''
    white_pieces = ['rook', 'knight', 'bishop', 'king', 'queen', 'bishop', 'knight', 'rook',
                    'pawn', 'pawn', 'pawn', 'pawn', 'pawn', 'pawn', 'pawn', 'pawn']
    white_locations = [(0, 0), (1, 0), (2, 0), (3, 0), (4, 0), (5, 0), (6, 0), (7, 0),
                       (0, 1), (1, 1), (2, 1), (3, 1), (4, 1), (5, 1), (6, 1), (7, 1)]
    black_pieces = ['rook', 'knight', 'bishop', 'king', 'queen', 'bishop', 'knight', 'rook',
                    'pawn', 'pawn', 'pawn', 'pawn', 'pawn', 'pawn', 'pawn', 'pawn']
    black_locations = [(0, 7), (1, 7), (2, 7), (3, 7), (4, 7), (5, 7), (6, 7), (7, 7),
                       (0, 6), (1, 6), (2, 6), (3, 6), (4, 6), (5, 6), (6, 6), (7, 6)]
    captured_pieces_white = []
    captured_pieces_black = []
    turn_step = 0
    selection = 100
    valid_moves = []
    update_options()

# main game loop
black_options = check_options(black_pieces, black_locations, 'black')
white_options = check_options(white_pieces, white_locations, 'white')
run = True
while run:
    timer.tick(fps)
    screen.fill('dark gray')
    draw_board()
    draw_pieces()
    taken_pieces()
    draw_check()
    if selection != 100:
        draw_valid(check_valid_moves())
    # event handling
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False
        if event.type == pygame.MOUSEBUTTONDOWN and event.button == 1 and not game_over:
            x_coord, y_coord = event.pos[0] // 100, event.pos[1] // 100
            click_coords = (x_coord, y_coord)
            if turn_step <= 1:
                if click_coords in [(8, 8), (9, 8)]:
                    winner = 'black'
                elif click_coords in white_locations:
                    selection = white_locations.index(click_coords)
                    if turn_step == 0:
                        turn_step = 1
                elif click_coords in check_valid_moves() and selection != 100:
                    white_locations[selection] = click_coords
                    if click_coords in black_locations:
                        black_piece = black_locations.index(click_coords)
                        captured_pieces_white.append(black_pieces[black_piece])
                        if black_pieces[black_piece] == 'king':
                            winner = 'white'
                        black_pieces.pop(black_piece)
                        black_locations.pop(black_piece)
                    update_options()
                    turn_step, selection = 2, 100
            elif turn_step > 1:
                if click_coords in [(8, 8), (9, 8)]:
                    winner = 'white'
                elif click_coords in black_locations:
                    selection = black_locations.index(click_coords)
                    if turn_step == 2:
                        turn_step = 3
                elif click_coords in check_valid_moves() and selection != 100:
                    black_locations[selection] = click_coords
                    if click_coords in white_locations:
                        white_piece = white_locations.index(click_coords)
                        captured_pieces_black.append(white_pieces[white_piece])
                        if white_pieces[white_piece] == 'king':
                            winner = 'black'
                        white_pieces.pop(white_piece)
                        white_locations.pop(white_piece)
                    update_options()
                    turn_step, selection = 0, 100
        if event.type == pygame.KEYDOWN and game_over:
            if event.key == pygame.K_RETURN:
                reset_game()

    if winner:
        game_over = True
        draw_Game_Over()

    pygame.display.flip()

pygame.quit()
