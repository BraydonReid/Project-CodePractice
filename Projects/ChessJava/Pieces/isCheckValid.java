package Pieces;

import Board.Board;

public class isCheckValid {

    private static Position findKing(Board board, boolean isWhite) {
        char[][] charBoard = board.getBoard();
        char king = ' ';
        if (isWhite) {
            king = 'K';
        } else {
            king = 'k';
        }

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (charBoard[i][j] == king) {
                    return new Position(i, j);
                }
            }
        }
        return null;
    }

    public static boolean isCheckValid(Board board, boolean isWhite) {
        Position kingPos = findKing(board, isWhite);
        if (kingPos == null) {
            return false;
        }

        int kingX = kingPos.getRow();
        int kingY = kingPos.getCol();
        char[][] charBoard = board.getBoard();

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                char piece = charBoard[i][j];
                if (isWhite && piece >= 'a' && piece <= 'z') {
                    Position start = new Position(i, j);
                    Position end = new Position(kingX, kingY);
                    pieces attacker = pieces.getPiece(piece);
                    if (attacker != null && attacker.canMove(board, start, end)) {
                        return false;
                    }
                } else if (!isWhite && piece >= 'A' && piece <= 'Z') {
                    Position start = new Position(i, j);
                    Position end = new Position(kingX, kingY);
                    pieces attacker = pieces.getPiece(piece);
                    if (attacker != null && attacker.canMove(board, start, end)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    public static boolean isCheckMate(Board board, boolean isWhite) {
        if (isCheckValid(board, isWhite)) {
            return false;
        }

        char[][] charBoard = board.getBoard();
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                char piece = charBoard[i][j];
                if ((isWhite && piece >= 'A' && piece <= 'Z') || (!isWhite && piece >= 'a' && piece <= 'z')) {
                    Position start = new Position(i, j);
                    pieces movingPiece = pieces.getPiece(piece);
                    if (movingPiece != null) {
                        for (int k = 0; k < 8; k++) {
                            for (int l = 0; l < 8; l++) {
                                Position end = new Position(k, l);
                                if (movingPiece.canMove(board, start, end)) {
                                    Board newBoard = new Board(board);
                                    newBoard.move(start, end);
                                    if (isCheckValid(newBoard, isWhite)) {
                                        return false;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
}
