#include <bits/stdc++.h>
using namespace std;

class Role
{
public:
    string role, name;
    vector<Role *> subRoles;
    Role(string roleName)
    {
        this->role = roleName;
        this->name = "";
    }
};

Role *root = NULL;

Role *searchRole(string targetRole)
{
    queue<Role *> q;
    for (auto i : root->subRoles)
        q.push(i);
    int count = q.size();
    while (count--)
    {
        if(q.front()->role == targetRole)
            return q.front();
        if(q.front()->subRoles.size() != 0)
        {
            for (auto i : q.front()->subRoles)
                q.push(i);
        }
        q.pop();
        if (count = 0)
        {
            cout << endl;
            count = q.size();
        }
    }
    Role *temp=NULL;
    return temp;
}

void AddSubRole()
{
    string subRoleName, reportingRoleName;
    cout << "Enter Sub role name:";
    cin >> subRoleName;
    cout << "Enter reporting role name:";
    cin >> reportingRoleName;
    Role *temp1 = searchRole(reportingRoleName);
    Role temp2 = Role(subRoleName);
    temp1->subRoles.push_back(&temp2);
}
void DisplayRoles()
{
    queue<Role *> q;
    cout << root->role << endl;
    for (auto i : root->subRoles)
        q.push(i);
    int count = q.size();
    while (count--)
    {
        cout << q.front()->role << " ";
        if (q.front()->subRoles.size() != 0)
        {
            for (auto i : q.front()->subRoles)
                q.push(i);
        }
        q.pop();
        if (count = 0)
        {
            cout << endl;
            count = q.size();
        }
    }
}

void DeleteRole()
{
    string role;
    queue<Role *> q;
    bool flag = 1;
    cout << "Enter the role to be deleted:";
    cin >> role;
    Role *temp = searchRole(role);
    Role *prev;
    for (auto i : root->subRoles)
    {
        q.push(i);
    }
    while (q.size() && flag)
    {
        for (auto i : q.front()->subRoles)
        {
            if (i->role == role)
            {
                prev = q.front();
                flag = 0;
                break;
            }
        }
    }

    for (auto i : temp->subRoles)
        prev->subRoles.push_back(i);

    for (int i = 0; i < prev->subRoles.size(); i++)
    {
        if (prev->subRoles[i]->role == role)
            prev->subRoles.erase(prev->subRoles.begin() + i);
    }
    free(temp);
}

void AddUser()
{
    string userName, role;
    cout << "Enter User Name: ";
    cin >> userName;
    cout << "Enter Role: ";
    cin >> role;
    Role *temp = searchRole(role);
    temp->name = userName;
}
void DisplayUsers(Role *Root)
{
    queue<Role *> q;
    for (auto i : Root->subRoles)
        q.push(i);

    int count = q.size();
    while (count--)
    {
        if (q.front()->name.length() > 0)
            cout << q.front()->name << "-" << q.front()->role << endl;
        if (q.front()->subRoles.size() != 0)
        {
            for (auto i : q.front()->subRoles)
                q.push(i);
        }
        q.pop();
        if (count = 0)
        {
            cout << endl;
            count = q.size();
        }
    }
    return;
}

void DisplayUsersAndSubUsers()
{
    queue<Role *> q;
    for (auto i : root->subRoles)
        q.push(i);

    int count = q.size();
    while (count--)
    {
        if (q.front()->name.length() != 0)
            DisplayUsers(q.front());
        if (q.front()->subRoles.size() != 0)
        {
            for (auto i : q.front()->subRoles)
                q.push(i);
        }
        q.pop();
        if (count = 0)
        {
            cout << endl;
            count = q.size();
        }
    }
}
void DeleteUser()
{
    string userName;
    cout << "Enter username to be deleted :";
    cin >> userName;
    queue<Role *> q;
    for (auto i : root->subRoles)
        q.push(i);
    for (int i = 0; i < q.size(); i++)
    {
        Role *temp = q.front();
        if (temp->name == userName)
        {
            temp->name = "";
            return;
        }
        q.pop();
        i--;
        if (temp->subRoles.size() != 0)
        {
            for (auto j : temp->subRoles)
                q.push(j);
        }
    }
}

void NumberOfUsersFromTop()
{
    string userName;
    cout << "Enter user name : ";
    cin >> userName;
    int result = 1;
    queue<Role *> q;
    for (auto i : root->subRoles)
        q.push(i);
    int count = q.size();
    while (count--)
    {
        if (q.front()->name == userName)
        {
            cout << "Number of users from top : " << result << endl;
            return;
        }
        if (q.front()->subRoles.size() != 0)
        {
            for (auto i : q.front()->subRoles)
                q.push(i);
        }
        q.pop();
        if (count = 0)
        {
            result++;
            count = q.size();
        }
    }
}

void HeightOfRoleHierarchy()
{
    int result = 1;
    queue<Role *> q;
    for (auto i : root->subRoles)
        q.push(i);
    int count = q.size();
    while (count--)
    {
        if (q.front()->subRoles.size() != 0)
        {
            for (auto i : q.front()->subRoles)
                q.push(i);
        }
        q.pop();
        if (count = 0)
        {
            result++;
            count = q.size();
        }
    }
    cout << "height - " << result << endl;
}

void CommonBossOfUsers()
{
    string user1, user2;
    cout << "user1 - " << user1;
    cin >> user1;
    cout << "user2 - " << user2;
    cin >> user2;
    int k = 0;
    queue<Role *> q;
    for (auto i : root->subRoles)
        q.push(i);
    int count = q.size();
    while (count--)
    {
        for (auto i : q.front()->subRoles)
        {
            if (i->name == user1 || i->name == user2)
                k++;
        }
        if (k == 2)
        {
            cout << "Top most common boss :" << q.front()->name << endl;
            return;
        }
        k = 0;
        if (q.front()->subRoles.size() != 0)
        {
            for (auto i : q.front()->subRoles)
                q.push(i);
        }
        q.pop();
        if (count = 0)
            count = q.size();
    }
}

int main()
{
    string rootRole;
    cout << "Enter root role name : ";
    cin >> rootRole;
    *root = Role(rootRole);
    int choice;
    while(true)
    {
        cout << "Operations :" << endl;
        cout << "1. Add Sub Role." << endl;
        cout << "2. Display Roles." << endl;
        cout << "3. Delete Role." << endl;
        cout << "4. Add User." << endl;
        cout << "5. Display Users." << endl;
        cout << "6. Display Users and Sub Users." << endl;
        cout << "7. Delete User." << endl;
        cout << "8. Number of users from top." << endl;
        cout << "9. Height of role hierachy." << endl;
        cout << "10. Common boss of users." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            AddSubRole();
            break;
        case 2:
            DisplayRoles();
            break;
        case 3:
            DeleteRole();
            break;
        case 4:
            AddUser();
            break;
        case 5:
            DisplayUsers(root);
            break;
        case 6:
            DisplayUsersAndSubUsers();
            break;
        case 7:
            DeleteUser();
            break;
        case 8:
            NumberOfUsersFromTop();
            break;
        case 9:
            HeightOfRoleHierarchy();
            break;
        case 10:
            CommonBossOfUsers();
            break;
        default:
            return 0;
        }
    }
}