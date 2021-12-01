
def cost_finder(lis,v,side):
    """
    lis : list of values
    v : target volume 
    side : left > 1, right > 2, init >1
    """
    if len(lis) >= 4:
        k = len(lis)//2
        left_lis, right_lis = lis[:k], lis[k:]
        cl, indl = cost_finder(left_lis,v,1)
        if cl == 0:
            return 0,indl 
        cr, indr = cost_finder(right_lis,v,2)
        if cr == 0:
            return 0,indr
        else:
            indr = (indr[0]+k,indr[1]+k)
            point_lis = [indl, indr]
            cost_list = [cl, cr]

            I = [lis[indl[0]], lis[indl[1]], lis[indr[0]], lis[indr[1]]]
            
            inter_max = max(lis[indl[1]+1:indr[0]]) if lis[indl[1]+1:indr[0]] != [] else 0
            if inter_max != 0:
                max_inds = [indl[1]+1+index for index, value in enumerate(lis[indl[1]+1:indr[0]]) if value == inter_max]
            if (min(lis[indl[1]], lis[indr[0]]) >= inter_max):
                s = (2*v/(indr[0]-indl[1]))-(lis[indr[0]]+lis[indl[0]])
                cost_list.append(s)
                point_lis.append((indl[1],indr[0]))

            if (lis[indl[1]] <= min(lis[indl[0]], lis[indr[0]])) and (inter_max <= max(lis[indl[0]], lis[indr[0]])):
                s = (2*v/(indr[0]-indl[0]))-(lis[indl[0]]+lis[indr[0]])
                cost_list.append(s)
                point_lis.append((indl[0], indr[0]))
            
            if lis[indr[0]] <= min(lis[indl[1]], lis[indr[1]]) and (inter_max <= max(lis[indl[1]], lis[indr[1]])):
                s = (2*v/(indr[1]-indl[1]))-(lis[indl[1]]+lis[indr[1]])
                cost_list.append(s)
                point_lis.append((indl[1],indr[1]))
        

            if (max(lis[indl[1]], lis[indr[0]]) <= min(lis[indl[0]],lis[indr[1]])) and (max(lis[indl[1]], lis[indr[0]]) >= inter_max):
                s = (2*v/(indr[1]-indl[0]))-(lis[indr[1]]+lis[indl[0]])
                cost_list.append(s)
                point_lis.append((indl[0],indr[1]))

            if inter_max >= I[1]:
                s = (2*v/(max_inds[-1]-indl[1]))-(I[1]+inter_max)
                cost_list.append(s)
                point_lis.append((indl[1],max_inds[-1]))

                if I[0] >= I[1]:
                    s = (2*v/(max_inds[-1]-indl[0]))-(I[0]+inter_max)
                    cost_list.append(s)
                    point_lis.append((indl[0],max_inds[-1]))

                    left_max = max(lis[:indl[0]]) if lis[:indl[0]] != [] else 0
                    if left_max != 0:
                        left_min_ind = [index for index, value in enumerate(lis[:indl[0]]) if value == left_max][0]

                        if left_max >= I[0]:
                            s = (2*v/(max_inds[-1]-left_min_ind))-(left_max+inter_max)
                            cost_list.append(s)
                            point_lis.append((left_min_ind,max_inds[-1]))

            if inter_max >= I[2]:
                s = (2*v/(indr[0]-max_inds[0]))-(I[2]+inter_max)
                cost_list.append(s)
                point_lis.append((max_inds[0], indr[0]))

                if I[3] >= I[2]:
                    s = (2*v/(indr[1]-max_inds[0]))-(I[3]+inter_max)
                    cost_list.append(s)
                    point_lis.append((max_inds[0], indr[1]))

                    right_max = max(lis[indr[1]+1:]) if lis[indr[1]+1:] != [] else 0
                    if right_max != 0:
                        right_max_ind = [indr[1]+1+index for index, value in enumerate(lis[indr[1]+1:]) if value == right_max][-1]

                        if right_max >= I[3]:
                            s = (2*v/(right_max_ind-max_inds[0]))-(right_max+inter_max)
                            cost_list.append(s)
                            point_lis.append((max_inds[0],right_max_ind))

            if any(i<0 for i in cost_list):
                return 0, []
            else:
                min_inds = [i for i,val in enumerate(cost_list) if val==min(cost_list)]
                if len(min_inds) == 1:
                    return cost_list[min_inds[0]], point_lis[min_inds[0]]
                else:
                    gaps = [point_lis[i][1]-point_lis[i][0] for i in min_inds]
                    max_gap_points = [min_inds[i] for i,val in enumerate(gaps) if val == max(gaps)]
                    if len(max_gap_points) == 2:
                        if side == 1:
                            return cost_list[min_inds[0]], point_lis[min_inds[0]]
                        else:
                            return cost_list[min_inds[1]], point_lis[min_inds[1]]
    else:
        if len(lis) == 2:
            return 2*v-(lis[0]+lis[1]), (0, 1)
        else:
            if lis[1]<=min(lis[0],lis[2]):
                return v-(lis[0]+lis[2]), (0,2)
            else:
                if 2*v-(lis[0]+lis[1])<2*v-(lis[2]+lis[1]):
                    return 2*v-(lis[0]+lis[1]), (0,1)
                else:
                    return 2*v-(lis[2]+lis[1]), (1,2)

if __name__ == '__main__':
    m = int(input())
    for i in range(m):
        v, n = list(map(int, input().split()))
        lis = list(map(int, input().split()))
        res = cost_finder(lis, v, 1)[0]
        # print(res)
        print(format(round(res,3), '.3f'))