#!/bin/bash
echo "Creating temp folder to save the libft  and the script to the git"
echo "Cloning git..."
git clone git@github.com:JeyDot-dev/TheLibft ~/tmp_script_folder
cp rf libft ~/tmp_script_folder/TheLibft/
cp ~/scripts/git_libft.sh ~/tmp_script_folder/git_libft.sh
echo "Adding, Comitting and Pushing"
git -C ~/tmp_script_folder add .
git -C ~/tmp_script_folder commit -m "Automated backup"
git -C ~/tmp_script_folder push
echo "Deleting temporary folder"
rm -rf ~/tmp_script_folder
echo "Done !"
