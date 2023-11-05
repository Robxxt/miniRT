# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_in_docker.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 09:38:43 by rdragan           #+#    #+#              #
#    Updated: 2023/11/05 10:38:49 by rdragan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# check weather the image exists or not and connect to it
if [ -z "$(docker images | grep mini_rt_env)" ]; then
	# build the container
	docker build -t mini_rt_env .
	# run the container
	docker run mini_rt_env
	for i in $(docker ps -a | grep "mini_rt_env" | awk '{print $1}');do echo Removed: && docker rm $i; done
else
	# run the container
	docker run mini_rt_env
	# remove containers
	for i in $(docker ps -a | grep "mini_rt_env" | awk '{print $1}');do echo Removed: && docker rm $i; done
	
	echo "Do you want to remove image?[Y/N]"
	read option
	if [ $option == "Y" ]; then
		docker rmi $(docker images | grep mini_rt_env | awk '{print $3}')
	elif [ $option == "Y" ]; then
		docker rmi $(docker images | grep mini_rt_env | awk '{print $3}')
	fi
fi