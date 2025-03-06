package Pieces;

import Board.Board;

public class Pawn extends pieces {

    int x = -1;
    int y = -1;

    String image = "";

    public Pawn(boolean isWhite) {
        super(isWhite);
    }

    public Pawn(boolean isWhite, int x, int y) {
        super(isWhite);
        this.x = x;
        this.y = y;
    }

    public int getValue() {
        return 1;
    }

    public String getImage() {
        if (isWhite()) {
            image = "/ChessPieceImages/WhitePawn.png";
        } else {
            image = "/ChessPieceImages/BlackPawn.png";
        }
        return image;
    }

    public boolean canMove(Board board, Position start, Position end) {
        int startRow = start.getRow();
        int startCol = start.getCol();
        int endRow = end.getRow();
        int endCol = end.getCol();

        char[][] boardArray = board.getBoard();

        // Use to trouble Shoot
        // System.out.println("Pawn Move - Start Position: (" + startRow + ", " +
        // startCol + ")");
        // System.out.println("Pawn Move - End Position: (" + endRow + ", " + endCol +
        // ")");

        if (startRow == endRow && startCol == endCol) {
            System.out.println("Destination is the same as the start position.");
            return false;
        }

        // Check if same color piece is in the end position
        if (isWhite() && boardArray[endRow][endCol] >= 65 && boardArray[endRow][endCol] <= 90) {
            return false;
        }
        if (!isWhite() && boardArray[endRow][endCol] >= 97 && boardArray[endRow][endCol] <= 122) {
            return false;
        }

        if (startCol == endCol) {
            // White pawn moves top to down
            if (this.isWhite()) {
                if (endRow == startRow + 1 && !board.hasPiece(end)) {
                    return true;
                }
                if (startRow == 1 && endRow == startRow + 2 && !board.hasPiece(end)
                        && !board.hasPiece(new Position(startRow + 1, startCol))) {
                    return true;
                }
            }
            // Black pawn moves down to top
            else {
                if (endRow == startRow - 1 && !board.hasPiece(end)) {
                    return true;
                }
                if (startRow == 6 && endRow == startRow - 2 && !board.hasPiece(end)
                        && !board.hasPiece(new Position(startRow - 1, startCol))) {
                    return true;
                }
            }
        }

        // Pawn capture movement
        if (Math.abs(startCol - endCol) == 1) {
            if (this.isWhite() && endRow == startRow + 1 && board.hasPiece(end) && !board.getPiece(end).isWhite()) {
                return true;
            }
            if (!this.isWhite() && endRow == startRow - 1 && board.hasPiece(end) && board.getPiece(end).isWhite()) {
                return true;
            }
        }

        // System.out.println("Invalid pawn move.");
        return false;
    }
}
