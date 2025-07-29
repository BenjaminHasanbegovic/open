#include "../../include/ui/UIElement.h"

void UIElement::addChild(std::shared_ptr<UIElement> child) {
    if (!child) return;
    child->setParent(this);
    child->setParentId(this->id);
    children[child->getId()] = std::move(child);
}

void UIElement::removeChild(uint32_t childId) {
    children.erase(childId);
}

std::vector<std::shared_ptr<UIElement>> UIElement::getChildren() const {
    std::vector<std::shared_ptr<UIElement>> result;
    result.reserve(children.size());
    for (const auto& [id, childPtr] : children) {
        // Non-owning wrapper
        result.emplace_back(std::shared_ptr<UIElement>(childPtr.get(), [](UIElement*) {}));
    }
    return result;
}

UIElement* UIElement::getParent() const {
    return parent;
}

void UIElement::setParent(UIElement* parentElement) {
    parent = parentElement;
}
