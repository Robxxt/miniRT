# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_in_docker.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 09:38:43 by rdragan           #+#    #+#              #
#    Updated: 2023/11/04 10:31:41 by rdragan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# # build the container
docker build -t mini_rt_env .
# # run the container
docker run mini_rt_env

sleep 1

# remove all containers and images
for image in $(docker images | grep -E 'none|mini_rt_env' | awk '{print $3}'); do
	for cotainer_list in $image; do
		for i in $(docker ps -a | grep -E 'mini_rt_env' | awk '{print $1}'); do
			docker stop $i
			docker rm $i
		done
	done
	docker rmi $image
done