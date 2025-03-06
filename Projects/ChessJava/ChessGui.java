import java.awt.event.*;
import java.awt.*;
import javax.swing.*;
import Pieces.*;
import Board.Board;
import java.util.Stack;
import Board.SavedMoves;

public class ChessGui {
    private JPanel boardPanel;
    private String currentPlayerTurn = "White";
    private ChessCell selectedCell;
    private Board gameBoard;
    private Stack<SavedMoves> undoStack = new Stack<>();
    private Stack<SavedMoves> redoStack = new Stack<>();
    private JFrame boardFrame;

    public ChessGui() {
        gameBoard = new Board();
        boardFrame = new JFrame("Chess Game");
        CreateBoard(gameBoard);
    }

    public void CreateBoard(Board currentBoard) {
        boardPanel = new JPanel();
        boardPanel.setLayout(new GridLayout(8, 8));
        gameBoard = new Board(currentBoard);

        char[][] boardArray = gameBoard.getBoard();

        JPanel PrimaryPanel = new JPanel(new BorderLayout());

        JPanel MainMenu = new JPanel();
        JButton newGame = new JButton("New Game");
        JButton exitGame = new JButton("Quit Game");
        JButton undoMove = new JButton("Undo Move");
        JButton redoMove = new JButton("Redo Move");

        newGame.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                gameBoard = new Board();
                currentPlayerTurn = "White";
                undoStack.clear();
                redoStack.clear();
                refreshWindow();
            }
        });

        exitGame.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        undoMove.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (!undoStack.isEmpty()) {
                    SavedMoves lastMove = undoStack.pop();
                    lastMove.undoMove(gameBoard);
                    redoStack.push(lastMove);
                    refreshWindow();

                    if (currentPlayerTurn.equals("White")) {
                        currentPlayerTurn = "Black";
                    } else {
                        currentPlayerTurn = "White";
                    }
                    System.out.printf("%s's turn.\n", currentPlayerTurn);
                } else {
                    JOptionPane.showMessageDialog(null, "No more moves to undo.");
                }
            }
        });

        redoMove.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (!redoStack.isEmpty()) {
                    SavedMoves lastMove = redoStack.pop();
                    lastMove.redoMove(gameBoard);
                    undoStack.push(lastMove);
                    refreshWindow();

                    if (currentPlayerTurn.equals("White")) {
                        currentPlayerTurn = "Black";
                    } else {
                        currentPlayerTurn = "White";
                    }
                    System.out.printf("%s's turn.\n", currentPlayerTurn);
                } else {
                    JOptionPane.showMessageDialog(null, "No moves to redo.");
                }
            }
        });

        MainMenu.add(newGame);
        MainMenu.add(exitGame);
        MainMenu.add(undoMove);
        MainMenu.add(redoMove);

        JPanel rankPanel = new JPanel(new GridLayout(8, 1));
        for (int i = 8; i > 0; i--) {
            JLabel rankLabel = new JLabel(String.valueOf(i), SwingConstants.CENTER);
            rankLabel.setFont(new Font("Arial", Font.BOLD, 20));
            rankPanel.add(rankLabel);
        }

        JPanel filePanel = new JPanel(new GridLayout(1, 8));
        for (char c = 'A'; c <= 'H'; c++) {
            JLabel fileLabel = new JLabel(String.valueOf(c), SwingConstants.CENTER);
            fileLabel.setFont(new Font("Arial", Font.BOLD, 20));
            filePanel.add(fileLabel);
        }

        for (int rank = 0; rank < 8; rank++) {
            for (int file = 0; file < 8; file++) {
                JButton button = new JButton();
                ChessCell chessCell = new ChessCell(rank, file);
                buttonAction listener = new buttonAction(rank, file);
                listener.setButton(button);
                listener.setChessCell(chessCell);
                button.addActionListener(listener);

                char pieceChar = boardArray[rank][file];

                if (pieceChar != '-') {
                    String pieceName = "";
                    boolean isWhite = Character.isUpperCase(pieceChar);
                    pieceChar = Character.toUpperCase(pieceChar);

                    switch (pieceChar) {
                        case 'P':
                            pieceName = "Pawn";
                            break;
                        case 'R':
                            pieceName = "Rook";
                            break;
                        case 'N':
                            pieceName = "Knight";
                            break;
                        case 'B':
                            pieceName = "Bishop";
                            break;
                        case 'Q':
                            pieceName = "Queen";
                            break;
                        case 'K':
                            pieceName = "King";
                            break;
                    }

                    String color = "";
                    if (isWhite) {
                        color = "White";
                    } else {
                        color = "Black";
                    }

                    String imagePath = "/ChessPiecesImages/" + color + pieceName + ".png";

                    button.setIcon(new javax.swing.ImageIcon(getClass().getResource(imagePath)));
                    chessCell.setPlayer(color);
                }

                chessCell.setButton(button);

                if ((rank + file) % 2 == 0) {
                    button.setBackground(Color.GREEN);
                } else {
                    button.setBackground(Color.WHITE);
                }

                boardPanel.add(button);
            }
        }

        PrimaryPanel.add(MainMenu, BorderLayout.NORTH);
        PrimaryPanel.add(rankPanel, BorderLayout.WEST);
        PrimaryPanel.add(filePanel, BorderLayout.SOUTH);
        PrimaryPanel.add(boardPanel, BorderLayout.CENTER);

        boardFrame.add(PrimaryPanel);
        boardFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        boardFrame.setSize(1000, 1000);

        boardFrame.setResizable(false);

        boardFrame.setVisible(true);
    }

    private void refreshWindow() {
        boardFrame.dispose();
        boardFrame = new JFrame("Chess Game");
        CreateBoard(gameBoard);
    }

    public static void main(String[] args) {
        Board gameBoard = new Board();
        ChessGui game = new ChessGui();
        game.CreateBoard(gameBoard);
    }

    private class ChessCell {
        private String player;
        private final int rank;
        private final int file;
        private JButton button;

        public ChessCell(int rank, int file) {
            this.rank = rank;
            this.file = file;
        }

        public int getRank() {
            return this.rank;
        }

        public int getFile() {
            return this.file;
        }

        public void setPlayer(String player) {
            this.player = player;
        }

        public String getPlayer() {
            return this.player;
        }

        public void setButton(JButton button) {
            this.button = button;
        }

        public JButton getButton() {
            return this.button;
        }
    }

    private class buttonAction implements ActionListener {
        private int rank;
        private int file;
        private JButton button;
        private ChessCell cell;

        public buttonAction(int rank, int file) {
            this.rank = rank;
            this.file = file;
        }

        public void setChessCell(ChessCell cell) {
            this.cell = cell;
        }

        public void setButton(JButton button) {
            this.button = button;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            Icon piece = this.button.getIcon();

            if (selectedCell == null) {
                if (cell.getPlayer() != null && cell.getPlayer().equals(currentPlayerTurn) && piece != null) {
                    System.out.printf("Piece selected at (%d, %d).\n", this.rank, this.file);
                    selectedCell = cell;
                }
            } 
            else if (this.file == selectedCell.getFile() && this.rank == selectedCell.getRank()) {
                System.out.println("Piece has been de-selected.\n");
                selectedCell = null;
            } else {

                if (cell.getPlayer() == null || !cell.getPlayer().equals(selectedCell.getPlayer())) {                    
                    Position start = new Position(selectedCell.getRank(), selectedCell.getFile());
                    Position end = new Position(this.rank, this.file);
                    char pieceChar = gameBoard.getBoard()[start.getRow()][start.getCol()];
                    pieces movingPiece = pieces.getPiece(pieceChar);

                    if (movingPiece != null && movingPiece.canMove(gameBoard, start, end)) {
                        char takenPiece = gameBoard.getBoard()[end.getRow()][end.getCol()];
                        SavedMoves lastMove = new SavedMoves(start, end, pieceChar, takenPiece, currentPlayerTurn.equals("White"), takenPiece != '-');
                        undoStack.push(lastMove);
                        redoStack.clear();

                        Board tempBoard = new Board(gameBoard);
                        tempBoard.move(start, end);
                        boolean isWhiteTurn = currentPlayerTurn.equals("White");

                        if (isCheckValid.isCheckValid(tempBoard, isWhiteTurn)) {
                            gameBoard.move(start, end);

                            this.button.setIcon(selectedCell.getButton().getIcon());
                            selectedCell.getButton().setIcon(null);
                            cell.setPlayer(selectedCell.getPlayer());
                            selectedCell.setPlayer(null);

                            boolean opponentIsWhite = !isWhiteTurn;
                            if (!isCheckValid.isCheckValid(gameBoard, opponentIsWhite)) {
                                if (isCheckValid.isCheckMate(gameBoard, opponentIsWhite)) {
                                    JOptionPane.showMessageDialog(null, "Checkmate! " + currentPlayerTurn + " wins!");
                                    System.exit(0);
                                } else {
                                    JOptionPane.showMessageDialog(null, "Check!");
                                }
                            }

                            currentPlayerTurn = isWhiteTurn ? "Black" : "White";
                            System.out.printf("%s's turn.\n", currentPlayerTurn);
                            selectedCell = null;
                        } else {
                            System.out.println("Your King is still in check after that move. Try again.");
                            JOptionPane.showMessageDialog(null,
                                    "Your King is still in check after that move. Try again.");
                        }
                    } else {
                        System.out.println("Invalid move.");
                        JOptionPane.showMessageDialog(null, "Invalid move.");
                    }
                }
            }
        }
    }
}
