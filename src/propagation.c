void propagate(int x_pos , int y_pos ){
    
    if (x_pos < 0 || x_pos >= W) // Position X hors plateau
        return ;    

    if (y_pos < 0 || y_pos >= H) // Position Y hors plateau
        return ;

    if (tab[x_pos][y_pos].val == ' ' && tab[x_pos][y_pos].isHidden == 0) //Deja éxploré 
        return ; 

    if (tab[x_pos][y_pos].val == 'X' ) //BOMB
        return ;
        
    if (tab[x_pos][y_pos].isHidden == 1 && tab[x_pos][y_pos].val = '■'){
        tab[x_pos][y_pos].val = ' ';
        tab[x_pos][y_pos].isHidden = 0;
    }
    if (tab[x_pos][y_pos].isHidden == 1 && tab[x_pos][y_pos].val == '1'){
        tab[x_pos][y_pos].isHidden = 0;
        tab[x_pos][y_pos].val = '1';
        return ; 
    }
    if (tab[x_pos][y_pos].isHidden == 1 && tab[x_pos][y_pos].val == '2'){
        tab[x_pos][y_pos].isHidden = 0;
        tab[x_pos][y_pos].val = '2';
        return ; 
    }
    if (tab[x_pos][y_pos].isHidden == 1 && tab[x_pos][y_pos].val == '3'){
        tab[x_pos][y_pos].isHidden = 0;
        tab[x_pos][y_pos].val = '3';
        return ; 
    }
    if (tab[x_pos][y_pos].isHidden == 1 && tab[x_pos][y_pos].val == '4'){
        tab[x_pos][y_pos].isHidden = 0;
        tab[x_pos][y_pos].val = '4';
        return ; 
    }
    if (tab[x_pos][y_pos].isHidden == 1 && tab[x_pos][y_pos].val == '5'){
        tab[x_pos][y_pos].isHidden = 0;
        tab[x_pos][y_pos].val = '5';
        return ; 
    }
    if (tab[x_pos][y_pos].isHidden == 1 && tab[x_pos][y_pos].val == '6'){
        tab[x_pos][y_pos].isHidden = 0;
        tab[x_pos][y_pos].val = '6';
        return ; 

    }
    if (tab[x_pos][y_pos].isHidden == 1 && tab[x_pos][y_pos].val == '7'){
        tab[x_pos][y_pos].isHidden = 0;
        tab[x_pos][y_pos].val = '7';
        return ; 

    }
    if (tab[x_pos][y_pos].isHidden == 1 && tab[x_pos][y_pos].val == '8'){
        tab[x_pos][y_pos].isHidden = 0;
        tab[x_pos][y_pos].val = '8';
        return ; 

    }

    
    if (tab[x_pos][y_pos] == 0){
        propagate(x_pos + 1 ,y_pos);
        propagate(x_pos - 1,y_pos);
        propagate(x_pos,y_pos + 1);
        propagate(x_pos,y_pos - 1);
    }
}