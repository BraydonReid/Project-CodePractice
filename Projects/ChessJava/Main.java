import Board.Board;
import Pieces.Position;
import Pieces.pieces;
import java.util.Scanner;
import AIChess.ChessAI;
import Pieces.isCheckValid;

public class Main {

    public static void main(String[] args) {

        int turn = 0;

        System.out.println("Welcome to Chess!");

        Scanner scanner = new Scanner(System.in);

            Board chessBoard = new Board();
            chessBoard.printBoard();

            while (true) {
                if (turn % 2 == 0) {

                    // if (isCheckValid.isCheckValid(chessBoard, true)) {
                    //     System.out.println("Player 1 is in check!");
                    // }
                    
                    // if (isCheckValid.isCheckMate(chessBoard, true)){
                    //     System.out.println("Player 2 wins!");
                    //     break;
                    // }

                    System.out.println("Player 1's turn. (White pieces or Capital letters)");

                } else {

                    // if (isCheckValid.isCheckValid(chessBoard, false)) {
                    //     System.out.println("Player 2 is in check!");
                    // }

                    if (isCheckValid.isCheckMate(chessBoard, false)){
                        System.out.println("Player 1 wins!");
                        break;
                    }

                    System.out.println("Player 2's turn. (Black pieces or Lowercase letters)");
                }
                System.out.println("Enter the row and column of the piece you want to move: ");
                int startRow = scanner.nextInt();
                int startCol = scanner.nextInt();

                System.out.println("Enter the row and column of the destination: ");
                int endRow = scanner.nextInt();
                int endCol = scanner.nextInt();

                Position start = new Position(startRow, startCol);
                Position end = new Position(endRow, endCol);

                // Whos turn is it?
                if (turn % 2 == 0) {
                    if (!chessBoard.getPiece(start).isWhite()) {
                        System.out.println("Wrong Player! Try again.");
                        continue;
                    }
                }
                if (turn % 2 == 1) {
                    if (chessBoard.getPiece(start).isWhite()) {
                        System.out.println("Wrong Player! Try again.");
                        continue;
                    }
                }

                if (!chessBoard.isValidPosition(start) || !chessBoard.isValidPosition(end)) {
                    System.out.println("Invalid position. Try again.");
                    continue;
                }
                pieces piece = chessBoard.getPiece(start);

                System.out.println("Attempting to move " + piece.getClass().getSimpleName() + " from (" + startRow + ","
                        + startCol + ") to (" + endRow + "," + endCol + ").");

                if (piece.canMove(chessBoard, start, end)) {
                    chessBoard.setPiece(end, chessBoard.getBoard()[startRow][startCol]);
                    chessBoard.setPiece(start, '-');
                    System.out.println("Move successful!");
                } else {
                    System.out.println("Invalid move for " + piece.getClass().getSimpleName() + ". Try again.");
                }
                turn++;
                chessBoard.printBoard();
            }
        }
    }

