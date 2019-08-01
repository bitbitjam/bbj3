#install Vundle
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim

#install plugins that are specified in ~/.vimrc
vim +PluginInstall +qall

#compile YCM
cd ~/.vim/bundle/YouCompleteMe
./install.py --clang-completer
